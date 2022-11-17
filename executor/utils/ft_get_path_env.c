/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:45:02 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:41:45 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	Cette fonction crêer un double tableau contenant tout les PATH à partir 
	des variables d'environements

	PARAMETRE : envp, doucle tableau contenant les variables d'environements

	VALEUR DE RETOUR: La fonction renvoie le double tableau ou renvoie NULL
	si il y a eu un probleme.
*/

char	**ft_get_path_env(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(&envp[i][5], ':');
			if (!path)
				return (NULL);
			else
				return (path);
		}
		i++;
	}
	return (NULL);
}
