/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:38:11 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:54:39 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	Cette fonction va simplement skip les espaces et les tab.

	PARAMETRES:
		- La string
		- L'indice du permier espace ou \t
	
	VALEUR DE RETOUR:
		- L'indice du prochain caractere différent
*/

int	ft_skip_space(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (i);
	}
	return (i);
}
