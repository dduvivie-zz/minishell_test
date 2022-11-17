/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_env_var_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/17 00:24:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Count the number of env variables */
int	ft_count_env_var(t_env *env)
{
	int		counter;
	t_env	*curr_env_var;

	counter = 0;
	curr_env_var = env;
	while (curr_env_var != NULL)
	{
		counter++;
		curr_env_var = curr_env_var->next;
	}
	return (counter);
}

/*
Compaire the two string key1 and key2.
Return 1 if key1 > key2
Return 0 if not so.
*/
int	ft_need_to_swap(char *key1, char	*key2)
{
	if (!key1 || !key2)
		return (0);
	while (*key1 == *key2 && *key1 && *key2)
	{
		key1++;
		key2++;
	}
	if (*key1 == '\0' && *key2 == '\0')
		return (0);
	else if (*key1 != '\0' && *key2 == '\0')
		return (1);
	else if (*key1 == '\0' && *key2 != '\0')
		return (0);
	else if (*key1 > *key2)
		return (1);
	return (0);
}

/* Swap two consecutive elements in linked list */
t_env	*ft_swap_env_var(t_env *prev_env_var, t_env *env_var)
{
	t_env	*tmp_env_var;

	tmp_env_var = env_var->next;
	env_var->next = tmp_env_var->next;
	tmp_env_var->next = env_var;
	if (prev_env_var != NULL)
		prev_env_var->next = tmp_env_var;
	return (tmp_env_var);
}

/*
Sort all env variables of the linked list.
The string "key" is compaired to sort the list.
*/
t_env	*ft_sort_env_var_list(t_env *head_env_var)
{
	int		times_to_check;
	t_env	*curr_env_var;
	t_env	*prev_env_var;

	times_to_check = ft_count_env_var(head_env_var) - 1;
	while (times_to_check > 0)
	{
		curr_env_var = head_env_var;
		prev_env_var = NULL;
		while (curr_env_var != NULL && curr_env_var->next != NULL)
		{
			if (ft_need_to_swap(curr_env_var->key, curr_env_var->next->key))
			{
				curr_env_var = ft_swap_env_var(prev_env_var, curr_env_var);
				if (prev_env_var == NULL)
					head_env_var = curr_env_var;
			}
			prev_env_var = curr_env_var;
			curr_env_var = curr_env_var->next;
		}
		times_to_check--;
	}
	return (head_env_var);
}
