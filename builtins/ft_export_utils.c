/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/17 00:28:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_puterror(char *arg, char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("export", 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(str, 2);
	return (0);
}

/*
If the export argument is in form "key+=value",
join the new value with the old value of the specific key.
*/
char	*ft_get_new_env_val(char *str, char *key, int *add, t_env *env)
{
	char	*value;
	char	*new_env_val;

	value = ft_copy_env_val(str);
	if (!value)
		return (NULL);
	if (*add)
	{
		new_env_val = ft_strjoin(value, ft_get_env_var(key, env));
		if (!new_env_val)
		{
			free(value);
			return (NULL);
		}
		free(value);
		value = NULL;
	}
	else
		new_env_val = value;
	return (new_env_val);
}

int	ft_is_valid_first_char(char c)
{
	if (!ft_isalpha(c) && c != '_')
		return (0);
	return (1);
}

int	ft_is_valid_char(char c)
{
	if (ft_isalnum(c))
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

/* Check if the argument for export command is valid or not. */
int	ft_is_valid_export(char *arg, int *add_flag, int *equal_flag)
{
	int	i;

	i = 0;
	if (!ft_is_valid_first_char(arg[i]))
		return (0);
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (arg[i] == '+')
		{
			if (arg[i + 1] == '\0' || arg[i + 1] != '=')
				return (0);
			else
				*add_flag = 1;
		}
		else
		{
			if (!ft_is_valid_char(arg[i]))
				return (0);
		}
		i++;
	}
	if (arg[i] == '=')
		*equal_flag = 1;
	return (1);
}
