/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Get with key, the value of the environment variable. */
char	*ft_get_env_var(char *key, t_env *env)
{
	t_env	*env_var;

	env_var = env;
	while (env_var != NULL)
	{
		if (ft_strncmp(key, env_var->key, ft_strlen(key) + 1) == 0)
			return (env_var->value);
		env_var = env_var->next;
	}
	return (NULL);
}
