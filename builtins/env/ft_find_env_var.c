/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Search if the environment variable with the "key" exist in the linked list.
Return True(1) or False(0).
*/
int	ft_is_env_var_exist(char *key, t_env *env)
{
	t_env	*env_var;

	env_var = env;
	while (env_var != NULL)
	{
		if (ft_strncmp(key, env_var->key, ft_strlen(key) + 1) == 0)
			return (1);
		env_var = env_var->next;
	}
	return (0);
}
