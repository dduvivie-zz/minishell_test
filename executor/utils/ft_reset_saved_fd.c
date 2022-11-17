/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_saved_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:35:30 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:44:32 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	La fonction ft_reset_saved_fd va restaurer les fd 0 et 1 sur
	STDIN ET STDOUT

	PARAMETRE: La structure contenant les fd à modifier
*/

int	ft_resest_fd_in(t_node *node)
{
	if (node->saved_stdin > -1)
	{
		if (dup2(node->saved_stdin, 0) == -1)
			return (-1);
	}
	return (0);
}

int	ft_reset_fd_out(t_node *node)
{
	if (node->saved_stdout > -1)
	{
		if (dup2(node->saved_stdout, 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_reset_saved_fd(t_node *node)
{
	if (ft_resest_fd_in(node) == -1)
		return (ft_err_dup());
	if (ft_reset_fd_out(node) == -1)
		return (ft_err_dup());
	return (0);
}
