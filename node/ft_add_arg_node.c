/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_arg_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:15:28 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:10:35 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_new(char **new, int i)
{
	while (i <= 0)
	{
		if (new[i])
			free(new[i]);
		i--;
	}
	if (new)
		free(new);
}

char	**ft_realloc_matrice(char **matrice)
{
	int		i;
	char	**new;

	i = 0;
	if (matrice == NULL)
		return (NULL);
	while (matrice[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = -1;
	while (matrice[++i])
	{
		new[i] = ft_strdup(matrice[i]);
		if (!new[i])
		{
			ft_free_new(new, i);
			return (NULL);
		}
		free(matrice[i]);
	}
	new[i + 1] = 0;
	free(matrice);
	return (new);
}

int	ft_first_arg(t_node *node, char *arg)
{
	node->arg = (char **)malloc(sizeof(char *) * 2);
	if (!node->arg)
		return (-1);
	node->arg[0] = ft_strdup(arg);
	if (!node->arg[0])
	{
		if (node->arg)
			free(node->arg);
		return (-1);
	}
	node->arg[1] = 0;
	return (0);
}

int	ft_add_arg_node(t_node *node, char *arg)
{
	int	i;

	i = 0;
	if (!node || !arg)
		return (-1);
	if (node->arg == NULL)
	{
		if (ft_first_arg(node, arg) < 0)
			return (-1);
	}
	else
	{
		while (node->arg[i])
			i++;
		node->arg = ft_realloc_matrice(node->arg);
		if (!node->arg)
			return (-1);
		node->arg[i] = ft_strdup(arg);
		if (!node->arg[i])
			return (-1);
	}
	return (0);
}
