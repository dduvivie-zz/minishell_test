/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_by_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:32:09 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:28:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	La fonction get_env_by_key retourne la valeur associé à la variable
	d'environement spécifié par key.

	ATTENTION: Key doit termnier par un '=' (exemple: "HOME=")

	Valeur de retour: Renvoie la valeur ou NULL si elle ne trouve
	pas ou qu'il y a un probleme d'allocation
*/

char	*ft_get_value_env(char *key, char *line)
{
	char	*value;
	int		i;

	i = 0;
	while (key[i])
		i++;
	value = ft_strdup(&line[i]);
	if (!value)
		return (NULL);
	return (value);
}

char	*ft_get_env_by_key(char *key, char **envp)
{
	int	i;

	i = 0;
	if (!key || !envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(key, envp[i], ft_strlen(key)) == 0)
			return (ft_get_value_env(key, envp[i]));
		i++;
	}
	return (NULL);
}
