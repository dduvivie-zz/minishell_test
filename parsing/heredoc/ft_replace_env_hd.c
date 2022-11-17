/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_env_hd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:13:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 03:16:03 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_key_hd(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] && ft_good_c_for_env(str[i]) == 1)
		i++;
	key = (char *)malloc(sizeof(char) * (i + 1));
	if (!key)
		return (NULL);
	key[0] = str[0];
	i = 0;
	while (str[i] && ft_good_c_for_env(str[i]) == 1)
	{
		key[i] = str[i];
		i++;
	}
	return (key);
}

char	*ft_swap_empty_env_hd(char *old, char *key, int i)
{
	char	*new;

	new = ft_strjoin(ft_substr(old, 0, i),
			ft_substr(old, (i + ft_strlen(key) + 1), ft_strlen(old)));
	if (old)
		free(old);
	return (new);
}

char	*ft_swap_env_hd(char *old, char *key, char *value, int i)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(ft_substr(old, 0, i), value);
	if (!tmp)
		return (tmp);
	new = ft_strjoin(tmp, ft_substr(old, (i + ft_strlen(key) + 1),
				ft_strlen(old)));
	if (tmp)
		free(tmp);
	if (old)
		free(old);
	if (!new)
		return (NULL);
	return (new);
}

char	*ft_get_env_hd(t_data_parsing *p, char *old, int i)
{
	char	*key;
	char	*value;
	char	*new;

	key = ft_get_key_hd(&old[i + 1]);
	if (!key)
		return (NULL);
	if (ft_get_env_value(key, &value, p->envp) == -1)
	{
		free(key);
		return (NULL);
	}
	if (value == NULL)
		new = ft_swap_empty_env_hd(old, key, i);
	else
		new = ft_swap_env_hd(old, key, value, i);
	if (value)
		free (value);
	if (key)
		free(key);
	return (new);
}

char	*ft_replace_env_hd(t_data_parsing *p, char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	new = ft_strdup(str);
	if (!new)
		return (NULL);
	while (new[i])
	{
		if (new[i + 1])
		{
			if (new[i] == '$' && ft_good_c_for_env(new[i + 1]) == 1)
			{
				new = ft_get_env_hd(p, new, i);
				if (!new)
					return (NULL);
			}
		}
		i++;
	}
	return (new);
}
