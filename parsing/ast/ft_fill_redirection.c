/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:38:15 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 16:10:25 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La fonction ft_fill_redireciton va l'ajouter à la liste des 
	redrection de la node.

	PARAMETRES:
		- La node à laquelle ajouter la redirection
		- Le token contenant la redirection
	
	VALEUR DE RETOUR:
		- Retourne 0 si tout se passe bien
		- Retourne -1 si une erreur de malloc est trouvée
*/

int	ft_fill_redirection(t_node *node, t_token *token)
{
	if (ft_set_redirection(node, token->type, -1,
			token->red_file_name) == -1)
		return (-1);
	return (0);
}
