/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:52:04 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/16 06:22:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_data	*ft_initialize_data(t_data *data, char **envp)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->env_var_list = ft_get_env_var_list(envp);
	if (data->env_var_list == NULL)
	{
		free(data);
		return (NULL);
	}
	data->envp = ft_env_list_to_char(data->env_var_list);
	if (!data->envp)
	{
		ft_free_env_var(data->env_var_list);
		free(data);
	}
	data->first_node = NULL;
	data->path_env = NULL;
	return (data);
}

void	ft_initialize_minishell(void)
{
	struct termios	tty_attr;

	ioctl(STDIN_FILENO, TIOCGETA, &tty_attr);
	tty_attr.c_lflag &= ~ECHOCTL;
	ioctl(STDIN_FILENO, TIOCSETA, &tty_attr);
	g_exit_status = 0;
	ft_signal_handler();
}

void	ft_quit_minishell(t_data *data)
{
	char		*up;
	char		*ri;

	ft_free_data(data);
	up = tgetstr("up", NULL);
	ri = tgetstr("RI", NULL);
	tputs(ri, 1, putchar);
	tputs(ri, 1, putchar);
	tputs(ri, 1, putchar);
	tputs(up, 1, putchar);
	printf("\bexit\n");
	exit(0);
}

void	routine(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("Minishell> ");
		if (line == NULL)
			ft_quit_minishell(data);
		if (ft_only_space(line) == 0)
		{
			add_history(line);
			if (ft_parsing(line, data) == -1)
			{
				ft_free_data(data);
				exit (1);
			}
		}
		else
		{
			g_exit_status = 0;
			if (line)
				free(line);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data *data;
		
	(void)argc;
	(void)argv;
	data = NULL;
	ft_initialize_minishell();
	data = ft_initialize_data(data, envp);
	if (!data)
	{
		ft_putstr_fd("Minshell: malloc error\n", 2);
		return (1);
	}
	routine(data);
}
