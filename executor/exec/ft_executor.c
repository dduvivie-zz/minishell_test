/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:11:00 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/16 07:00:21 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	Fonction principale de l'execution.

	1) ft_get_path_env va copier les différents path dans la strcuture

	2) ft_is_builtin va checker si la commande est un builtin

	3) ft_set_path_cmd va set le path de l'executable

*/

void	ft_executor_redirection(t_data *data)
{
	if (ft_open_files(data->first_node) == 0)
	{
		if (ft_save_in_out(data->first_node) == 0)
		{
			if (ft_set_redirection_fd(data->first_node) == 0)
				ft_exec_regular_cmd(data, data->first_node);
			ft_reset_saved_fd(data->first_node);
		}
	}
}

void	ft_executor(t_data *data)
{	
	g_exit_status = 0;
	data->path_env = ft_get_path_env(data->envp);
	if (!data->first_node)
		return ;
	if (!data->path_env)
		return (ft_err_malloc_exec());
	ft_is_builtin(data->first_node);
	if (data->env_var_list == NULL)
		return (ft_err_malloc_exec());
	if (ft_set_path_cmd(data) == -1)
		return ;
	if (data->first_node->redirection == NULL && data->first_node->next == NULL)
		ft_exec_regular_cmd(data, data->first_node);
	else if (data->first_node->redirection != NULL
		&& data->first_node->next == NULL)
		ft_executor_redirection(data);
	else
		ft_exec_pipe(data);
}
