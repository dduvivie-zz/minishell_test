/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/17 00:10:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Update the env variables list with adding the new variable,
or modifie the value of the specific variable.
*/
int	ft_update_env_var_list(char *key, char *value, t_env *env)
{
	t_env	*new_env_var;

	if (ft_is_env_var_exist(key, env))
	{
		ft_update_env_var(key, value, env);
		free(key);
	}
	else
	{
		new_env_var = ft_new_env_var(key, value);
		if (!new_env_var)
		{
			free(key);
			free(value);
			return (0);
		}
		env = ft_add_env_var(env, new_env_var);
	}
	return (1);
}

/*
Get the string for key and value.
If these two string are valids, update the env variables list.
*/
int	ft_export_env_var(char *str, int add_flag, t_env *env)
{
	char	*key;
	char	*value;

	key = ft_copy_env_key(str, add_flag);
	if (!key)
		return (0);
	value = ft_get_new_env_val(str, key, &add_flag, env);
	if (!value)
	{
		free(key);
		return (0);
	}
	if (!ft_update_env_var_list(key, value, env))
		return (0);
	return (1);
}

/*
Create temporary an env variables linked list,
then sort this list for output the content in order.
Once the content is printed, free the list.
*/
int	ft_put_env_var_sort_list(t_env *env, int fd_out)
{
	t_env	*temp_env_var_list;
	t_env	*env_var;

	temp_env_var_list = ft_copy_env_var_list(env);
	if (!temp_env_var_list)
		return (1);
	temp_env_var_list = ft_sort_env_var_list(temp_env_var_list);
	if (!temp_env_var_list)
		return (1);
	env_var = temp_env_var_list;
	while (env_var != NULL)
	{
		ft_putstr_fd("declare -x ", fd_out);
		ft_putstr_fd(env_var->key, fd_out);
		ft_putstr_fd("=\"", fd_out);
		ft_putstr_fd(env_var->value, fd_out);
		ft_putendl_fd("\"", fd_out);
		env_var = env_var->next;
	}
	ft_free_env_var_list(temp_env_var_list);
	return (0);
}

/* Set the export attribute for variables */
int	ft_builtin_export(int fd_out, char **args, t_env *env)
{
	int		add_flag;
	int		equal_flag;

	args++;
	if (*args == NULL)
		return (ft_put_env_var_sort_list(env, fd_out));
	while (*args != NULL)
	{
		add_flag = 0;
		equal_flag = 0;
		if (ft_is_valid_export(*args, &add_flag, &equal_flag))
		{
			if (equal_flag)
			{
				if (!ft_export_env_var(*args, add_flag, env))
					return (1);
			}
		}
		else
			ft_puterror(*args, "not a valid identifier");
		args++;
	}
	return (0);
}
