/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_redirection_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:56:28 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:11:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_has_redirection_type(t_node *node, int type)
{
	t_redir_list	*elem;

	elem = node->redirection;
	if (elem == NULL)
		return (0);
	while (1)
	{
		if (type == OUTFILE || type == OUTFILE_HAP)
		{
			if (elem->type == OUTFILE || elem->type == OUTFILE_HAP)
				return (1);
		}
		else if (type == INFILE || type == HEREDOC)
		{
			if (elem->type == INFILE || elem->type == HEREDOC)
				return (1);
		}
		if (elem->next == NULL)
			break ;
	}
	return (0);
}
