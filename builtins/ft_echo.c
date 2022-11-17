/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* check if -n is specified */
int	arg_is_option_n(char *arg)
{
	if (*arg != '-')
		return (0);
	arg++;
	while (*arg != '\0')
	{
		if (*arg != 'n')
			return (0);
		arg++;
	}
	return (1);
}

/*
Output the arguments.
If -n is specified, the trailing new line is suppressed.
*/
int	ft_builtin_echo(char **args, int fd_out)
{
	int	option_n;

	args++;
	option_n = 0;
	if (!*args)
		ft_putstr_fd("\n", fd_out);
	else
	{
		while (*args && arg_is_option_n(*args))
		{
			option_n = 1;
			args++;
		}
		while (*args)
		{
			ft_putstr_fd(*args, fd_out);
			args++;
			if (*args)
				ft_putstr_fd(" ", fd_out);
			else if (!option_n)
				ft_putstr_fd("\n", fd_out);
		}
	}
	return (0);
}
