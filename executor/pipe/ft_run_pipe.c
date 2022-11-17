/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:19:36 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:36:37 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_pipe(t_data *data, t_node *node)
{
	if (node->redirection == NULL)
		return (ft_exec_simple_pipe(data, node));
	else
	{
		ft_close_bad_pipe(data->first_node, node);
		if (ft_open_files(node) != 0)
			exit (1);
		if (ft_set_fd_pipe_red(node) < 0)
			exit (1);
		return (ft_exec_pipe_red(data, node));
	}
}
