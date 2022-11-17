/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Ptint all environment variables */
int	ft_builtin_env(int fd_out, t_env *env)
{
	t_env	*env_var;

	env_var = env;
	while (env_var != NULL)
	{
		ft_putstr_fd(env_var->key, fd_out);
		ft_putstr_fd("=", fd_out);
		ft_putendl_fd(env_var->value, fd_out);
		env_var = env_var->next;
	}
	return (0);
}
