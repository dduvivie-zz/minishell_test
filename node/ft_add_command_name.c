/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_command_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:16:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:10:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_split_path(t_node *node, char *command)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(command, '/');
	if (!split)
		return (-1);
	while (split[i])
		i++;
	i--;
	ft_add_arg_node(node, split[i]);
	ft_free_matrice(split);
	return (0);
}

int	ft_command_is_a_path(t_node *node, char *command)
{
	int	i;

	i = 0;
	if (!command || !node)
		return (0);
	while (command[i])
	{
		if (command[i] == '/')
		{
			ft_split_path(node, command);
			return (0);
		}
		i++;
	}
	ft_add_arg_node(node, command);
	return (0);
}

int	ft_add_command_name(t_node *node, char *command)
{
	node->command_name = ft_strdup(command);
	if (!node->command_name)
		return (-1);
	return (ft_command_is_a_path(node, command));
}
