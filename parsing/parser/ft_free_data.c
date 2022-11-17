/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:44:14 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/16 06:53:37 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_free_data(t_data *data)
{
	ft_free_matrice(data->envp);
	ft_free_env_var_list(data->env_var_list);
	if (data)
		free(data);
	return (-1);
}

int	ft_reset_ast(t_data *data)
{
	if (data->first_node)
		ft_free_nodes(data->first_node);
	if (data->path_env)
		ft_free_matrice(data->path_env);
	if (data->envp)
		ft_free_matrice(data->envp);
	data->first_node = NULL;
	data->envp = ft_env_list_to_char(data->env_var_list);
	if (data->envp == NULL)
		return (-1);
	return (0);
}

void	ft_free_data_exit(t_data *data)
{
	ft_reset_ast(data);
	ft_free_data(data);
}
