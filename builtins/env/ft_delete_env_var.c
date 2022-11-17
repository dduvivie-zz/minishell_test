/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_env_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:27:59 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/15 19:28:01 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Delete the env variable and free its memory */
int	ft_delete_env_var(char *key, t_env *env)
{
	t_env	*curr_env_var;
	t_env	*prev_env_var;

	curr_env_var = env;
	prev_env_var = NULL;
	while (curr_env_var != NULL)
	{
		if (ft_strncmp(key, curr_env_var->key, ft_strlen(key) + 1) == 0)
		{
			if (!prev_env_var)
				env = curr_env_var->next;
			else
				prev_env_var->next = curr_env_var->next;
			ft_free_env_var(curr_env_var);
			return (0);
		}
		prev_env_var = curr_env_var;
		curr_env_var = curr_env_var->next;
	}
	return (0);
}
