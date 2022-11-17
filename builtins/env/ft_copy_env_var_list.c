/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env_var_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:15:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/17 00:15:46 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Create a new linked list, copy the content of the param (t_env linked list),
then return the created list.
*/
t_env	*ft_copy_env_var_list(t_env *env_var)
{
	t_env	*env_var_list_copy;
	t_env	*env_var_copy;

	if (!env_var)
		return (NULL);
	env_var_list_copy = NULL;
	while (env_var != NULL)
	{
		env_var_copy = ft_new_env_var(ft_strdup(env_var->key), \
									ft_strdup(env_var->value));
		if (!env_var_copy)
		{
			ft_free_env_var_list(env_var_list_copy);
			return (NULL);
		}
		env_var_list_copy = ft_add_env_var(env_var_list_copy, env_var_copy);
		env_var = env_var->next;
	}
	return (env_var_list_copy);
}
