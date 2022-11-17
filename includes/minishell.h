/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:10:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/16 06:55:00 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <termcap.h>
# include <string.h>

# define ECHO_ 1
# define CD 2
# define PWD 3
# define EXPORT 4
# define UNSET 5
# define ENV 6
# define EXIT 7

# define REDIRECTION 5
# define PIPE 7
# define WORDS 8

# define OUTFILE 10
# define OUTFILE_HAP 11
# define INFILE 12
# define HEREDOC 13

# define ERR_MALLOC -1
# define ERROR -2

# define MAX_PATH_LEN 1024

struct	s_node;
struct	s_data;
struct	s_redir_list;
struct	s_token;
struct	s_saved_fd;
struct	s_env;

int		g_exit_status;

typedef struct s_data
{
	struct s_node	*first_node;
	struct s_env	*env_var_list;
	char			**envp;
	char			**path_env;
}	t_data;

typedef struct s_env
{
	char			*value;
	char			*key;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	char			*value;
	int				type;
	int				fd_heredoc;
	int				fd;
	char			*red_file_name;
	struct s_token	*next;
	struct s_token	*previous;
}	t_token;

typedef struct s_data_parsing
{
	struct s_token		*first_token;
	int					list_token_size;
	char				**envp;
}	t_data_parsing;

typedef struct s_redir_list
{
	int					type;
	int					fd;
	char				*file_name;
	struct s_redir_list	*next;
}	t_redir_list;

typedef struct s_node
{
	int					is_built_in;
	int					cmd_exist;
	char				*command_name;
	char				*path_cmd;
	char				**arg;
	struct s_node		*next;
	struct s_node		*previous;
	struct s_redir_list	*redirection;
	int					saved_stdin;
	int					saved_stdout;
	int					fd_in;
	int					fd_out;
	int					pipe_in;
	int					pipe_out;
	pid_t				pid;
}	t_node;

/* parser */
int				ft_parsing(char *input, t_data *data);
int				ft_free_data(t_data *data);
int				ft_reset_ast(t_data *data);
void			ft_free_data_exit(t_data *data);

/* token */
int				ft_create_token_list(t_data_parsing *data_p, char *input);
int				ft_set_char_list(t_data_parsing *data_p, char *input);
void			ft_free_token(t_token *token);
t_token			*ft_create_token(t_token *previous, t_data_parsing *p);
int				ft_cpy_in_quote(t_token *token, char *input, int i);
int				ft_set_word_token(t_data_parsing *p, t_token *token,
					char *input, int i);
int				ft_set_token_list(t_data_parsing *d, char *input);
int				ft_replace_env(t_data_parsing *p);
int				ft_change_env_token(t_token *token, int i, char **envp);
char			*ft_swap_env_token(t_token *token, char *value,
					int begin, int end);
int				ft_delete_quotes(t_data_parsing *p, int i);
void			ft_clear_token_list(t_data_parsing *p);
void			ft_delete_token_in_list(t_data_parsing *p, t_token *bad_token);
int				ft_check_redir_next(t_data_parsing *p, t_token *token);
int				ft_concat_redir(t_data_parsing *p);
int				ft_ambiguous_redirect(t_data_parsing *p);
int				ft_check_syntax(t_data_parsing *p);
int				ft_set_red_file_name(t_data_parsing *p);

/* utils */
int				ft_only_space(char *str);
int				ft_skip_space(char *str, int i);
int				ft_get_env_value(char *key, char **value, char **envp);
char			*ft_realloc_add(char *old, char c);
int				ft_err_pars_message(t_data_parsing *data_p,
					char *message, int err_code);
int				ft_err_pars_bad_char(t_data_parsing *data_p,
					char c, int err_code);
int				ft_err_pars_near(t_data_parsing *data_p,
					char *str, int err_code);
int				ft_err_pars_ambiguous(t_data_parsing *data_p, t_token *token,
					int err_code);
int				ft_err_pars_new_line(t_data_parsing *data_p,
					char *str, int err_code);
int				ft_is_separator(char c);
int				ft_is_autorized_char(t_data_parsing *p, char *input);
int				ft_autorized_char(char c);
void			ft_free_dp(t_data_parsing *data_p);
int				ft_good_c_for_env(char c);
int				ft_is_empty_token(t_token *token);
int				ft_is_redirection(t_token *token);
int				ft_is_directory(char *directory);
char			**ft_env_list_to_char(t_env *env);

/* ast */

int				ft_set_data(t_data *data, t_data_parsing *p);
int				ft_fill_redirection(t_node *node, t_token *token);

/* heredoc */

int				ft_set_heredoc(t_data_parsing *p);
char			*ft_random_name(void);
char			*ft_replace_env_hd(t_data_parsing *p, char *str);

/*
-------------------------------BUILTINS-----------------------------------------
*/

int				ft_call_builtin(t_node *node, t_env *env, t_data *data);
int				ft_builtin_echo(char **args, int fd_out);
int				ft_builtin_pwd(int fd_out);
int				ft_builtin_cd(char *dir);
int				ft_builtin_env(int fd_out, t_env *env);
int				ft_builtin_export(int fd_out, char **args, t_env *env);
int				ft_builtin_unset(char **args, t_env *env);
int				ft_builtin_exit(char **args, t_data *data);

/* utils */
int				ft_is_valid_export(char *arg, int *add_flag, int *equal_flag);
char			*ft_get_new_env_val(char *str, char *key, int *add, t_env *env);
int				ft_is_valid_unset(char *arg);
int				ft_is_valid_first_char(char c);
int				ft_is_valid_char(char c);
int				ft_puterror(char *arg, char *str);

/*
----------------------------------ENV-----------------------------------------
*/
t_env			*ft_get_env_var_list(char **envp);
t_env			*ft_sort_env_var_list(t_env *head_env_var);
t_env			*ft_copy_env_var_list(t_env *env);
t_env			*ft_add_env_var(t_env *first_env_var, t_env *new_env_var);
t_env			*ft_new_env_var(char *new_key, char *new_val);
char			*ft_copy_env_key(char *str, int add_flag);
char			*ft_copy_env_val(char *str);
char			*ft_get_env_var(char *key, t_env *env);
int				ft_is_env_var_exist(char *key, t_env *env);
int				ft_update_env_var(char *key, char *new_value, t_env *env);
int				ft_delete_env_var(char *key, t_env *env);
void			ft_free_env_var_list(t_env *env_var);
void			ft_free_env_var(t_env *env_var);

/*
----------------------------------NODE-----------------------------------------
*/

t_node			*ft_create_node(void);
t_node			*ft_new_node(t_node *previous_node);
t_redir_list	*ft_get_next_redirection(t_redir_list *li);
t_redir_list	*ft_get_last_redirection(t_redir_list *li);
int				ft_set_redirection(t_node *node, int redirect_type,
					int fd, char *f_name);
int				ft_add_arg_node(t_node *node, char *arg);
int				ft_add_command_name(t_node *node, char *command);
void			ft_free_nodes(t_node *node);
int				ft_has_redirection_type(t_node *node, int type);
int				ft_set_fd_pipe(t_node *node);
int				ft_has_redirection(t_node *node, int type);
void			ft_free_matrice(char **matrice);

/*
----------------------------------Executor--------------------------------------
*/

void			ft_executor(t_data *data);
int				ft_reset_saved_fd(t_node *node);
void			ft_wait_children(void);
char			**ft_get_path_env(char **envp);
int				ft_find_path_cmd(t_node *node, char **path_env);
void			ft_is_builtin(t_node *node);
int				ft_set_path_cmd(t_data *data);
int				ft_exec_regular_cmd(t_data *data, t_node *this_node);
int				ft_search_outfile_redir(t_redir_list *elem);
int				ft_search_infile_redir(t_redir_list *elem);
int				ft_exec_redirection(t_data *data, t_node *node);
char			*ft_get_env_by_key(char *key, char **envp);
int				ft_set_redirection_fd(t_node *node);
int				ft_count_node(t_node *node);
int				ft_create_pipe(t_data *data);
int				ft_exec_pipe(t_data *data);
void			ft_wait_one_children(pid_t pid);
int				ft_exec_regular(t_data *data, t_node *node);
void			ft_close_bad_pipe(t_node *first_node, t_node *current_node);
int				ft_exec_simple_pipe(t_data *data, t_node *node);
int				ft_exec_pipe(t_data *data);
int				ft_run_pipe(t_data *data, t_node *node);
int				ft_exec_pipe_red(t_data *data, t_node *node);
int				ft_open_files(t_node *node);
int				ft_err_dup(void);
int				ft_save_in_out(t_node *node);
int				ft_err_cmd_exist(t_node *node);
int				ft_err_fork(void);
void			ft_err_malloc_exec(void);
int				ft_reset_fd_out(t_node *node);
int				ft_reset_fd_in(t_node *node);
int				ft_set_fd_pipe_red(t_node *node);
int				ft_err_access(char *command_name);
void			ft_signal_handler(void);
void			rl_replace_line(const char *text, int clear_undo);
#endif
