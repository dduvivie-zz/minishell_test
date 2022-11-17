/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/16 06:56:00 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Call the corresponded builtin function.
Return 1 if an error occured.
*/
int	ft_call_builtin(t_node *node, t_env *env, t_data *data)
{
	int	command;

	command = node->is_built_in;
	if (command == ECHO)
		return (ft_builtin_echo(node->arg, node->fd_out));
	else if (command == CD)
		return (ft_builtin_cd(node->arg[1]));
	else if (command == PWD)
		return (ft_builtin_pwd(node->fd_out));
	else if (command == EXPORT)
		return (ft_builtin_export(node->fd_out, node->arg, env));
	else if (command == UNSET)
		return (ft_builtin_unset(node->arg, env));
	else if (command == ENV)
		return (ft_builtin_env(node->fd_out, env));
	else if (command == EXIT)
		return (ft_builtin_exit(node->arg, data));
	return (0);
}
