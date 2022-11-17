/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Init all str pointer to NULL */
void	ft_init_env_var(t_env *env_var)
{
	env_var->key = NULL;
	env_var->value = NULL;
	env_var->next = NULL;
}

/*
Create a new env variable, with new key and new value.
*/
t_env	*ft_new_env_var(char *new_key, char *new_val)
{
	t_env	*new_env_val;

	new_env_val = (t_env *)malloc(sizeof(t_env));
	if (!new_env_val)
		return (NULL);
	ft_init_env_var(new_env_val);
	new_env_val->key = new_key;
	new_env_val->value = new_val;
	if (!new_env_val->key || !new_env_val->value)
	{
		ft_free_env_var(new_env_val);
		return (NULL);
	}
	return (new_env_val);
}
