/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:27:21 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:56:03 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_has_redir_in(t_redir_list *elem)
{
	int	fd;

	fd = -1;
	while (1)
	{
		if (elem->type == INFILE || elem->type == HEREDOC)
			fd = elem->fd;
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	return (fd);
}

int	ft_has_redir_out(t_redir_list *elem)
{
	int	fd;

	fd = -1;
	while (1)
	{
		if (elem->type == OUTFILE || elem->type == OUTFILE_HAP)
			fd = elem->fd;
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	return (fd);
}

int	ft_has_redirection(t_node *node, int type)
{
	t_redir_list	*elem;
	int				fd;

	fd = -1;
	elem = node->redirection;
	if (type == INFILE)
		fd = ft_has_redir_in(elem);
	else if (type == OUTFILE)
		fd = ft_has_redir_out(elem);
	return (fd);
}
