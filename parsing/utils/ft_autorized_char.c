/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autorized_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:33:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:48:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	Cette fonction renvoie 0 si le c est un caractere autorisé et -1 si non.

*/

int	ft_autorized_char(char c)
{
	if (ft_isprint(c) == 0)
		return (-1);
	if (c == '!' || c == '#' || c == '*' || c == '&'
		|| c == '(' || c == ')' || c == ';' || c == '`')
		return (-1);
	return (0);
}
