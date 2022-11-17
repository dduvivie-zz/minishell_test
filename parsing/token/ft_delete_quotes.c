/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:54:40 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 21:18:49 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	Cette fonction va simplement supprimer les quotes contenue 
	dans les tokens

	PARAMETRE D'ENTREE:
		- La structure t_data_parsing qui contient le pointeur 
		du premier element token
	
	VALEUR DE RETOUR:
		- Renvoie 0 si tout se passe bien.
		- Renvoie -1 en cas d'erreur de malloc

*/

int	ft_remplace_quotes(t_token *token, int i, char quote)
{
	char	*new;

	new = NULL;
	i = -1;
	while (token->value[++i])
	{
		if (token->value[i] == '\'' || token->value[i] == '\"')
		{
			quote = token->value[i];
			i++;
			while (token->value[i] != quote)
			{
				new = ft_realloc_add(new, token->value[i]);
				i++;
			}
		}
		else
			new = ft_realloc_add(new, token->value[i]);
		if (!new)
			return (-1);
	}
	if (token->value)
		free(token->value);
	token->value = new;
	return (0);
}

int	ft_fill_null(t_token *token)
{
	if (token->value)
		free (token->value);
	token->value = (char *)malloc(sizeof(char) * 1);
	if (!token->value)
		return (-1);
	token->value[0] = '\0';
	return (0);
}

int	ft_contain_quotes(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (ft_strlen(str) == 2)
				return (2);
			return (1);
		}
		i++;
	}
	return (-1);
}

int	ft_delete_quotes(t_data_parsing *p, int i)
{
	t_token	*token;
	char	quote;

	token = p->first_token;
	quote = '\0';
	while (1)
	{
		if (token->type == WORDS)
		{
			if (ft_contain_quotes(token->value) == 1)
			{
				if (ft_remplace_quotes(token, i, quote) == -1)
					return (-1);
			}
			else if (ft_contain_quotes(token->value) == 2)
			{
				if (ft_fill_null(token) == -1)
					return (-1);
			}
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}
