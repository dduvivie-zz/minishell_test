/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:44:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/16 06:35:50 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La foncion ft_parsing est l'entrée de notre parsing.

	On commence par créer une structure t_data_parsing qui contiendra:

		- Le premier element de la liste des token.
		- Les variables d'environement.

	Ensuite elle va envoyer l'input et la liste au différentes fonction 
	qui va creer cette liste de tokens.

	FONCTION DE DEBBUGAGE A DELETE ET A REMETTRE A LA NORME
*/

int	ft_parsing(char *input, t_data *data)
{
	t_data_parsing	*data_p;

	data_p = (t_data_parsing *)malloc(sizeof(t_data_parsing));
	if (!data_p)
		return (ft_err_pars_message(data_p, "malloc error\n", -1));
	data_p->first_token = NULL;
	data_p->list_token_size = 0;
	data_p->envp = data->envp;
	if (ft_create_token_list(data_p, input) < 0)
		return (-1);
	free(input);
	data->first_node = NULL;
	if (ft_set_data(data, data_p) < 0)
		return (ft_free_data(data));
	ft_free_dp(data_p);
	ft_executor(data);
	if (ft_reset_ast(data))
	{
		ft_putstr_fd("Minishell: malloc error\n", 2);
		return (-1);
	}
	return (0);
}
