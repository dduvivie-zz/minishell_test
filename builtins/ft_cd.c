/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cd_to_path(char *path)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (0);
	}
	return (1);
}

int	cd_to_home(void)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (!home_dir)
		return (0);
	return (cd_to_path(home_dir));
}

/*
Change the current directory to dir.
If the param dir is NULL, change the current directory to $HOME.
 */
int	ft_builtin_cd(char *dir)
{
	if (dir == NULL)
	{
		if (!cd_to_home())
			return (1);
	}
	else
	{
		if (!cd_to_path(dir))
			return (1);
	}
	return (0);
}
