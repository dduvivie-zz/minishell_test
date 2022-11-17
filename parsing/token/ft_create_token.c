/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:07:17 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:29:30 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	Cette fonction va creer et allouer dynamiquement un élément token 
	et l'ajouter à la liste

	PARAMATRES: Le token précédent ou NULL si c'est le premier élément.

	VALEUR DE RETOUR: Retourne le nouveau token ou NULL si malloc échoue
*/

t_token	*ft_create_token(t_token *previous, t_data_parsing *p)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = NULL;
	new->type = -1;
	new->fd_heredoc = -1;
	new->fd = -1;
	new->next = NULL;
	new->red_file_name = NULL;
	new->previous = previous;
	if (previous != NULL)
		previous->next = new;
	p->list_token_size++;
	return (new);
}
