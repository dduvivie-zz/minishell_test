/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:14:44 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:29:30 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La fonction ft_is_builtin regarde si la commande envoyé est un builtin ou pas
	et modifie la valeur dans la node en fonction des macro

	PARAMETRE : La premiere node.

*/

void	ft_set_builtin(t_node *node)
{
	if (ft_strncmp(node->command_name, "echo",
			(ft_strlen(node->command_name) + 1)) == 0)
		node->is_built_in = ECHO;
	else if (ft_strncmp(node->command_name, "cd",
			(ft_strlen(node->command_name) + 1)) == 0)
		node->is_built_in = CD;
	else if (ft_strncmp(node->command_name, "pwd",
			(ft_strlen(node->command_name) + 1)) == 0)
		node->is_built_in = PWD;
	else if (ft_strncmp(node->command_name, "export",
			(ft_strlen(node->command_name) + 1)) == 0)
		node->is_built_in = EXPORT;
	else if (ft_strncmp(node->command_name, "unset",
			(ft_strlen(node->command_name) + 1)) == 0)
		node->is_built_in = UNSET;
	else if (ft_strncmp(node->command_name, "env",
			(ft_strlen(node->command_name) + 1)) == 0)
		node->is_built_in = ENV;
	else if (ft_strncmp(node->command_name, "exit",
			(ft_strlen(node->command_name) + 1)) == 0)
		node->is_built_in = EXIT;
}

void	ft_is_builtin(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return ;
	tmp = node;
	while (1)
	{
		if (tmp->command_name != NULL)
			ft_set_builtin(tmp);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
}
