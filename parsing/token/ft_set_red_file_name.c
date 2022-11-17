/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_red_file_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:26:58 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 22:26:23 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_insert_red_file_name(t_data_parsing *p, t_token *token, t_token *f_n)
{
	if (token->type != HEREDOC && ft_is_empty_token(f_n) == 1)
		return (ft_err_pars_message(p, ": No such files or drectory", -2));
	if (token->type != HEREDOC)
		token->red_file_name = ft_strdup(f_n->value);
	if (!token->red_file_name)
		return (-1);
	ft_delete_token_in_list(p, f_n);
	return (0);
}

int	ft_set_red_file_name(t_data_parsing *p)
{
	t_token	*token;
	int		exit_code;

	token = p->first_token;
	while (1)
	{
		if (ft_is_redirection(token) == 1)
		{
			exit_code = ft_insert_red_file_name(p, token, token->next);
			if (exit_code < 0)
				return (exit_code);
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}
