/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:50:24 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:11:12 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
	Cette fonction renvoie le dernier element de la liste de redirection.

	PARAMETRES:	- li: Un element de la liste.

	VALEUR DE RETOUR: Renvoie le dernier element ou NULL si le parametre est
	vide.
*/

t_redir_list	*ft_get_last_redirection(t_redir_list *li)
{
	t_redir_list	*tmp;

	tmp = li;
	if (li == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
