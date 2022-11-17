/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_in_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:03:16 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:28:06 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	La fonction ft_cpy_in_quote copie les caracteres 
	jusqu'à rencontrer la quote fermante.

	PARAMETRE:
		- Le token dans lequel copier l'input
		- L'input
		- l'indice de la premiere quote
		
	VALEUR DE RETOUR:
		- Renvoie l'index aprés la quote fermante.
		- Renvoie -1 si la quote fermante n'est pas trouvée
		- Renvoie -2 en cas d'erreur de malloc
*/

int	ft_cpy_in_quote(t_token *token, char *input, int i)
{
	char	quote;

	quote = input[i];
	token->value = ft_realloc_add(token->value, input[i]);
	if (!token->value)
		return (-2);
	i++;
	while (input[i] && input[i] != quote)
	{
		token->value = ft_realloc_add(token->value, input[i]);
		if (!token->value)
			return (-2);
		i++;
	}
	if (input[i] == '\0')
		return (-1);
	token->value = ft_realloc_add(token->value, input[i]);
	if (!token->value)
		return (-2);
	return (i);
}
