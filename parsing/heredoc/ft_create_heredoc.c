/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:33:08 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 23:47:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_condition_loop_hd(char *s1, char *s2)
{
	if (s2[0] == '\0')
	{
		if (s1[0] == '\0')
			return (0);
		else
			return (1);
	}
	else
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2) + 1) != 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ft_heredoc_loop(t_data_parsing *p, t_token *token, char *line)
{
	char	*line_w_env;

	line = readline("heredoc> ");
	while (ft_condition_loop_hd(line, token->next->value) == 1)
	{
		line_w_env = (ft_replace_env_hd(p, line));
		if (line_w_env == NULL)
		{
			if (line)
				free(line);
			close(token->fd);
			return (-1);
		}
		ft_putstr_fd(line_w_env, token->fd);
		ft_putchar_fd('\n', token->fd);
		if (line_w_env)
			free(line_w_env);
		if (line)
			free (line);
		line = readline("heredoc> ");
	}
	if (line)
		free(line);
	close(token->fd);
	return (0);
}

int	ft_create_heredoc(t_data_parsing *p, t_token *token)
{	
	token->red_file_name = ft_random_name();
	if (token->red_file_name == NULL)
		return (-1);
	token->fd = open(token->red_file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (token->fd == -1)
		return (ft_err_pars_message(p, "Can't open file for heredoc", -2));
	return (0);
}

int	ft_set_heredoc(t_data_parsing *p)
{
	t_token	*token;
	int		exit_code;
	char	*line;

	token = p->first_token;
	line = NULL;
	while (1)
	{
		if (token->type == HEREDOC)
		{
			if (token->next == NULL)
				return (ft_err_pars_near(p, "\n", -2));
			if (token->next->type != WORDS)
				return (ft_err_pars_near(p, token->next->value, -2));
			exit_code = ft_create_heredoc(p, token);
			if (exit_code < 0)
				return (exit_code);
			if (ft_heredoc_loop(p, token, line) == -1)
				return (-1);
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}
