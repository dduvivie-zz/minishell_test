/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:22:47 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:10:58 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_node(t_node *node)
{
	t_node	*tmp;
	int		i;

	i = 1;
	if (!node)
		return (0);
	tmp = node;
	if (tmp->next == NULL)
		return (i);
	while (1)
	{
		if (tmp->next == NULL)
			return (i);
		i++;
		tmp = tmp->next;
	}
}
