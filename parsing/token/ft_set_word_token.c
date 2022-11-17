/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_word_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:54:57 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:40:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	La fonction ft_set_word_token copie tout le mot ou la string jusqu'à
	rencontrer un séparateur

	PARAMETRE: 
		- La structure t_data_parsing
		- Le token dans lequel ajouter le mot ou la string
		- L'input
		- L'indice ou se trouve le mot ou la string dans l'input

	VALEUR DE RETOUR:
		- Renvoie l'index de fin en cas de réussite.
		- Renvoie -1 en cas d'erreur de malloc
		- Renvoie -2 Si un mauvais caractere est trouvé
		- Renvoie -3 Si une quote est non fermée
*/

int	ft_set_word_token(t_data_parsing *d, t_token *token, char *input, int i)
{
	while (input[i] && ft_is_separator(input[i]) == 0)
	{
		if (ft_autorized_char(input[i]) == -1)
			return (ft_err_pars_bad_char(d, input[i], -2));
		if (input[i] == '\"' || input[i] == '\'')
		{
			i = ft_cpy_in_quote(token, input, i);
			if (i == -1)
				return (ft_err_pars_message(d, "Unclosed Quote", -3));
			if (i == -2)
				return (-1);
		}
		else
		{
			token->value = ft_realloc_add(token->value, input[i]);
			if (!token->value)
				return (-1);
		}
		i++;
	}
	token->type = WORDS;
	return (i);
}
