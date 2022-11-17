/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_token_in_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:31:05 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 16:13:59 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_clear_one_token(t_token *token)
{
	if (token->value)
		free(token->value);
	if (token)
		free (token);
	token = NULL;
}

void	ft_delete_token_in_list(t_data_parsing *p, t_token *bad_token)
{
	t_token	*token;

	token = p->first_token;
	if (p->list_token_size == 1)
	{
		ft_clear_one_token(token);
		p->first_token = NULL;
		p->list_token_size--;
		return ;
	}
	while (token != bad_token)
		token = token->next;
	if (token->previous == NULL)
	{
		p->first_token = token->next;
		token->next->previous = NULL;
	}
	else
	{
		token->previous->next = token->next;
		if (token->next != NULL)
			token->next->previous = token->previous;
	}
	ft_clear_one_token(token);
	p->list_token_size--;
}
