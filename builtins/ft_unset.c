/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/16 06:31:45 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Check if the argument(name) has valid syntax */
int	ft_is_valid_unset(char *arg)
{
	int	i;

	i = 0;
	if (!ft_is_valid_first_char(arg[i]))
		return (0);
	while (arg[i] != '\0')
	{
		if (!ft_is_valid_char(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Unset the env variable specified by its name(key) */
int	ft_builtin_unset(char **args, t_env *env)
{
	args++;
	while (*args != NULL)
	{
		if (ft_is_valid_unset(*args))
		{
			if (ft_is_env_var_exist(*args, env))
				ft_delete_env_var(*args, env);
		}
		else
			ft_puterror(*args, "not a valid identifier");
		args++;
	}
	return (0);
}
