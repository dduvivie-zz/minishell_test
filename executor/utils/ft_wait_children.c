/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_children.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:55:40 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 19:44:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La fonction ft_wait children va attendre que le processus enfant se
	termine

		-1 dans la fonction waitpid definit que le processus attend la fin 
		de n'importe lequel de ses fils

		WIFEXITED(status) renvoie vrai si le fils s'est terminer normalement

		WEXITSTATUS(status) renvoie le code de sortie du fils

		WIFSIGNALED(satus) renvoie vrai si le processus s'est terminé à cause
		d'un signal

		WTERMSIG renvoie le numéro de signal qui a causé la fin du fil 
		(seulement si WIFSIGNALED est vrai)
*/

void	ft_wait_one_children(pid_t pid)
{
	int		status;
	int		signal;

	printf("it okey\n");
	while (waitpid(pid, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			signal = WTERMSIG(status);
			g_exit_status = signal + 128;
		}		
	}
	printf("it okey2\n");
}

void	ft_wait_children(void)
{
	int		status;
	int		signal;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			signal = WTERMSIG(status);
			g_exit_status = signal + 128;
		}		
	}
}
