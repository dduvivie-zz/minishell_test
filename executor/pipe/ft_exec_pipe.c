/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:00:14 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:35:21 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_pipe_main(t_data *data)
{
	t_node	*node;

	node = data->first_node;
	while (1)
	{
		if (node->pipe_in > 0)
			close(node->pipe_in);
		if (node->pipe_out > 0)
			close(node->pipe_out);
		if (node->next == NULL)
			break ;
		node = node->next;
	}	
}

int	ft_exec_pipe(t_data *data)
{
	t_node	*node;

	node = data->first_node;
	ft_create_pipe(data);
	while (1)
	{
		node->pid = fork();
		if (node->pid < 0)
			return (ft_err_fork());
		else if (node->pid == 0)
			ft_run_pipe(data, node);
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	ft_close_pipe_main(data);
	ft_wait_children();
	return (0);
}
