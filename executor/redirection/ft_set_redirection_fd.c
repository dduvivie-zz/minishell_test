/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_redirection_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:59:42 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:38:53 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	Fonction qui va set les fd des redirection.
	Elle va changer le fd de STDIN et/ou STDOUT

	PARAMETRE: La node de la commande à modifier les redirection.

	RETURN: 
	- Renvoie 0 si tout se passe bien
	- Renvoie -1 si une erreur de dup est trouvée
*/

void	ft_close_other_fd(t_node *node, int last_in, int last_out)
{
	t_redir_list	*elem;

	elem = node->redirection;
	while (1)
	{
		if (elem->fd != last_in && elem->fd != last_out)
			close (elem->fd);
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
}

int	ft_set_infile_fd(int new_fd, int fd_in)
{
	if (dup2(new_fd, fd_in) == -1)
		return (-1);
	return (0);
}

int	ft_set_outile_fd(int new_fd, int fd_out)
{
	if (dup2(new_fd, fd_out) == -1)
		return (-1);
	return (0);
}

int	ft_set_redirection_fd(t_node *node)
{
	int	last_infile_fd;
	int	last_outfile_fd;

	last_infile_fd = ft_search_infile_redir(node->redirection);
	last_outfile_fd = ft_search_outfile_redir(node->redirection);
	if (last_infile_fd > -1)
	{
		if (ft_set_infile_fd(last_infile_fd, node->fd_in) == -1)
			return (ft_err_dup());
	}
	if (last_outfile_fd > -1)
	{
		if (ft_set_outile_fd(last_outfile_fd, node->fd_out) == -1)
			return (ft_err_dup());
	}
	return (0);
}
