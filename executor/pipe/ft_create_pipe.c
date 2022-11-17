/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:29:52 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:34:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	int pipe(int fd[2]) --> créé un pipe avec en renvoyant un tableau de fd 
	contenant le fd de lecture et le fd d'écriture

*/

int	ft_create_pipe(t_data *data)
{
	t_node	*node;
	t_node	*next;
	int		pipe_fd[2];

	node = data->first_node;
	next = node->next;
	while (1)
	{
		if (pipe(pipe_fd) == -1)
			return (-1);
		node->pipe_out = pipe_fd[1];
		next->pipe_in = pipe_fd[0];
		if (next->next == NULL)
			break ;
		node = node->next;
		next = next->next;
	}
	return (0);
}
