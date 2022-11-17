/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_to_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:12:59 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/16 05:00:54 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_env_char(char **new, int i)
{
	i--;
	while (i >= 0)
	{
		if(new[i])
			free(new[i]);
	}
}

int	ft_count_env(t_env *env)
{
	t_env *elem;
	int i;

	elem = env;
	i = 0;
	if (env == NULL)
		return (0);
	while (1)
	{
		i++;
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	return (i);
}

char 	*ft_join_env(t_env *elem, char *new)
{
	char	*tmp;

	tmp = ft_strjoin(elem->key, "=");
	if (!tmp)
		return (NULL);
	new = ft_strjoin(tmp, elem->value);
	free(tmp);
	if (!new)
		return (NULL);
	return (new);
}

char	**ft_set_env_char(t_env *env, char **new)
{
	t_env	*elem;
	int		i;
	
	i = 0;
	elem = env;
	while (1)
	{
		new[i] = ft_join_env(elem, new[i]);
		if (!new[i])
		{
			ft_free_env_char(new, i);
			return (NULL);
		}
		i++;
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	new[i] = 0;
	return (new);
}

char	**ft_env_list_to_char(t_env *env)
{
	char	**new;
	int		size;

	new = NULL;
	size = ft_count_env(env);
	if (size == 0)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	return (ft_set_env_char(env, new));
}
