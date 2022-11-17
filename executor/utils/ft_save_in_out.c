/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_in_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:23:20 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:43:51 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_save_in_out(t_node *node)
{
	if (ft_search_infile_redir(node->redirection) > -1 || node->pipe_in > -1)
	{
		node->fd_in = 0;
		node->saved_stdin = dup(0);
		if (node->saved_stdin == -1)
			return (ft_err_dup());
	}
	if (ft_search_outfile_redir(node->redirection) > -1 || node->pipe_out > -1)
	{
		node->fd_out = 1;
		node->saved_stdout = dup(1);
		if (node->saved_stdout == -1)
			return (ft_err_dup());
	}
	return (0);
}
