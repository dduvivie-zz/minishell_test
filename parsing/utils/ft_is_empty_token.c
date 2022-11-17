/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_empty_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:11:12 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:53:04 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_empty_token(t_token *token)
{
	if (!token)
		return (1);
	if (token->type == WORDS)
	{
		if (ft_strlen(token->value) == 0)
			return (1);
		if (ft_strlen(token->value) == 2)
		{
			if (token->value[0] == '\'' && token->value[1] == '\'')
				return (1);
			if (token->value[0] == '\"' && token->value[1] == '\"')
				return (1);
		}
	}
	return (0);
}
