/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fd_pipe_red.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:48:48 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:37:32 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	ft_set_pipe va set les fd sur le d'entrêe et/ou de sortie

*/

int	ft_set_fd_in(t_node *node)
{
	int	fd_file_in;

	fd_file_in = ft_search_infile_redir(node->redirection);
	if (fd_file_in == -1 && node->pipe_in <= 0)
		return (0);
	if (fd_file_in == -1 && node->pipe_in > 0)
	{
		if (dup2(node->pipe_in, 0) < 0)
			return (-1);
	}
	if (fd_file_in > -1)
	{
		if (node->pipe_in > 0)
			close(node->pipe_in);
		if (dup2(fd_file_in, 0) < 0)
			return (-1);
	}
	return (0);
}

int	ft_set_fd_out(t_node *node)
{
	int	fd_file_out;

	fd_file_out = ft_search_outfile_redir(node->redirection);
	if (fd_file_out == -1 && node->pipe_out <= 0)
		return (0);
	if (fd_file_out == -1 && node->pipe_out > 0)
	{
		if (dup2(node->pipe_out, 1) < 0)
			return (-1);
	}
	if (fd_file_out > -1)
	{
		if (node->pipe_out > 0)
			close(node->pipe_out);
		if (dup2(fd_file_out, 1) < 0)
			return (-1);
	}
	return (0);
}

int	ft_set_fd_pipe_red(t_node *node)
{
	if (ft_set_fd_out(node) == -1)
		return (ft_err_dup());
	if (ft_set_fd_in(node) == -1)
		return (ft_err_dup());
	return (0);
}
