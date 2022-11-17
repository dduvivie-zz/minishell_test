/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:01:03 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:11:15 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
	Cette fonction renvoie l'element suivant de la liste

	PARAMERTE:	- li: l'element de la liste

	VALEUR DE RETOUR: Renvoie l'element suivant. 

*/

t_redir_list	*ft_get_next_redirection(t_redir_list *li)
{
	if (li == NULL)
		return (NULL);
	return (li->next);
}
