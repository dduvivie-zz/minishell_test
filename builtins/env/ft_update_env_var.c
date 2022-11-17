/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Update the value of the environment variable found with key. */
int	ft_update_env_var(char *key, char *new_value, t_env *env)
{
	t_env	*env_var;

	if (!key || !new_value || !env)
		return (0);
	env_var = env;
	while (env_var != NULL)
	{
		if (ft_strncmp(key, env_var->key, ft_strlen(key) + 1) == 0)
		{
			free(env_var->value);
			env_var->value = NULL;
			env_var->value = new_value;
			return (1);
		}
		env_var = env_var->next;
	}
	return (0);
}
