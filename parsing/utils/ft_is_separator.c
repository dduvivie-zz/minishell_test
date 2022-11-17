/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 07:01:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:53:28 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	Cette fonction renvoie 1 si 'c' est un séparateur et 0 si non.
*/

int	ft_is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}
