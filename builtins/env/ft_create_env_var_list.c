/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env_var_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Get an env variable from the **envp */
t_env	*ft_get_one_env_var(char *env)
{
	char	*key;
	char	*value;
	t_env	*env_var;

	key = ft_copy_env_key(env, 0);
	if (!key)
		return (NULL);
	value = ft_copy_env_val(env);
	if (!value)
	{
		free(key);
		return (NULL);
	}
	env_var = ft_new_env_var(key, value);
	if (!env_var)
	{
		free (key);
		free (value);
		return (NULL);
	}
	return (env_var);
}

/* Create a linked list, which will contain all environment variables. */
t_env	*ft_get_env_var_list(char **envp)
{
	t_env	*env_var_list;
	t_env	*env_var;

	if (!envp)
		return (NULL);
	env_var_list = NULL;
	while (*envp)
	{
		env_var = ft_get_one_env_var(*envp);
		if (!env_var)
		{
			ft_free_env_var_list(env_var_list);
			return (NULL);
		}
		env_var_list = ft_add_env_var(env_var_list, env_var);
		envp++;
	}
	return (env_var_list);
}
