/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_bad_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:38:24 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:33:45 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_bad_pipe(t_node *first_node, t_node *current_node)
{
	t_node	*node;

	node = first_node;
	while (1)
	{
		if (node != current_node)
		{
			if (node->pipe_in > 0)
				close(node->pipe_in);
			if (node->pipe_out > 0)
				close(node->pipe_out);
		}
		if (node->next == NULL)
			break ;
		node = node->next;
	}
}
