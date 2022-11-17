/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:47:45 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:16:41 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_name_exist(char *name)
{
	struct dirent	*dir;
	DIR				*d;
	char			*directory;

	directory = (char *)malloc(sizeof(char) * OPEN_MAX);
	if (!directory)
		return (-1);
	directory = getcwd(directory, OPEN_MAX);
	d = opendir(directory);
	if (!d)
		return (-1);
	dir = readdir(d);
	while ((dir != NULL))
	{
		if (ft_strncmp(name, dir->d_name, ft_strlen(name) + 1) == 0)
		{
			closedir(d);
			free(directory);
			return (-2);
		}
		dir = readdir(d);
	}
	closedir(d);
	free (directory);
	return (0);
}

char	*ft_increase_name(char *random_name)
{
	int	i;

	i = -1;
	if (random_name[ft_strlen(random_name) - 1] < 'z')
		random_name[ft_strlen(random_name) - 1]++;
	else
	{
		while (random_name[++i])
			random_name[i] = 'a';
		random_name = ft_realloc_add(random_name, 'a');
		if (!random_name)
			return (NULL);
	}
	return (random_name);
}

char	*ft_random_name(void)
{
	char	*random_name;
	int		exit_code;

	exit_code = 1;
	random_name = (char *)malloc(sizeof(char) * 3);
	if (!random_name)
		return (NULL);
	random_name[0] = '.';
	random_name[1] = 'a';
	random_name[2] = '\0';
	if (!random_name)
		return (NULL);
	while (ft_check_name_exist(random_name) != 0)
	{
		exit_code = ft_check_name_exist(random_name);
		if (exit_code == -1)
			return (NULL);
		random_name = ft_increase_name(random_name);
		if (!random_name)
			return (NULL);
	}
	return (random_name);
}
