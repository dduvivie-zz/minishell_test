/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_env_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:50:04 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/14 21:41:05 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	Cette la fonction ft_change_env_token sert à remplacer les variables
	d'environement par leurs valeurs.
		- Elle va d'abord construire la key qui est le nom de
		la variable par exemple [$PATH]

		- Ensuite elle va chercher dans envp la valeur correspondant.

		- Ensuite elle l'envoie à ft_swap_env qui va swap la variable
		avec sa valeur.

	PARAMETRES: 
		- Le token contenant la variable
		- l'indice ou se trouve la variable dans la value du token.
		- Les varialbes d'environement

	VALEUR DE RETOUR: renvoie 0 si tout se passe bien et -1 en
	cas d'erreur de malloc.
*/

int	ft_change_env_ext(t_token *token, char *value, int saved_i, int i)
{
	token->value = ft_swap_env_token(token, value, saved_i, i);
	if (value)
		free (value);
	if (token->value == NULL)
		return (-1);
	return (0);
}

char	*ft_set_key(t_token *token, int *i)
{
	char	*key;

	key = NULL;
	if (token->value[*i] == '?')
	{
		key = ft_realloc_add(key, token->value[*i]);
		if (!key)
			return (NULL);
			*i = *i +1;
	}
	else
	{
		while (token->value[*i] && ft_good_c_for_env(token->value[*i]) == 1)
		{
			key = ft_realloc_add(key, token->value[*i]);
			if (key == NULL)
				return (NULL);
			*i = *i + 1;
		}
	}
	return (key);
}

int	ft_change_env_token(t_token *token, int i, char **envp)
{
	char	*key;
	char	*value;
	int		saved_i;

	saved_i = i;
	i++;
	if (token->value[i] == '\0')
		return (0);
	if (ft_good_c_for_env(token->value[i]) == -1 && token->value[i] != '?')
		return (0);
	key = ft_set_key(token, &i);
	if (key == NULL)
		return (-1);
	if (ft_get_env_value(key, &value, envp) == -1)
		return (-1);
	free(key);
	return (ft_change_env_ext(token, value, saved_i, i));
}
