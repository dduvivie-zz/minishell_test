/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:50:21 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/15 15:50:23 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Add a new env variable to the linked list */
t_env	*ft_add_env_var(t_env *first_env_var, t_env *new_env_var)
{
	t_env	*curr_env_var;

	if (first_env_var == NULL)
		first_env_var = new_env_var;
	else
	{
		curr_env_var = first_env_var;
		while (curr_env_var->next != NULL)
			curr_env_var = curr_env_var->next;
		curr_env_var->next = new_env_var;
	}
	return (first_env_var);
}
