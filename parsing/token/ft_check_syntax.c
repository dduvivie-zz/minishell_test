/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:10:47 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 23:48:01 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_add_input(t_data_parsing *new)
{
	char	*line;
	int		exit_code;

	line = readline("> ");
	while (ft_only_space(line) == 1)
	{
		if (line != NULL)
			free(line);
		line = readline("> ");
	}
	exit_code = ft_set_token_list(new, line);
	if (line)
		free(line);
	if (exit_code == -1)
		return (-1);
	else
		return (exit_code);
}

int	ft_pipe_end(t_data_parsing *p, t_token *token)
{
	t_data_parsing	*new;
	int				exit_code;

	if (token->next == NULL)
	{
		new = (t_data_parsing *)malloc(sizeof(t_data_parsing));
		if (!new)
			return (-1);
		exit_code = ft_add_input(new);
		if (exit_code < 0)
		{
			ft_free_dp(new);
			return (exit_code);
		}
		if (ft_concat_redir(new) < 0)
		{
			ft_free_dp(new);
			return (-1);
		}
		token->next = new->first_token;
		p->list_token_size += new->list_token_size;
		if (new)
			free (new);
	}
	return (0);
}

int	ft_check_syntax_pipe(t_data_parsing *p, t_token *token)
{
	t_token	*next;

	if (token->next == NULL)
		return (ft_pipe_end(p, token));
	next = token->next;
	if (next->type == PIPE)
	{
		if (next->next != NULL && next->next->type == PIPE)
			return (ft_err_pars_near(p, "||", -2));
		else
			return (ft_err_pars_near(p, "|", -2));
	}
	return (0);
}

char	*ft_first_pipe(t_token *token)
{
	if (token->next != NULL)
	{
		if (token->next->type == PIPE)
			return ("||");
	}
	return ("|");
}

int	ft_check_syntax(t_data_parsing *p)
{
	t_token	*token;
	int		exit_code;

	token = p->first_token;
	if (token->type == PIPE)
		return (ft_err_pars_new_line(p, ft_first_pipe(token), -2));
	while (1)
	{
		if (ft_is_redirection(token) == 1)
		{
			if (ft_check_redir_next(p, token) == -2)
				return (-2);
		}
		else if (token->type == PIPE)
		{
			exit_code = ft_check_syntax_pipe(p, token);
			if (exit_code < 0)
				return (exit_code);
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}
