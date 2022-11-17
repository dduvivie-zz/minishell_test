/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:11:26 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 20:11:27 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
	Cette fonction créé et ajoute un element node à la liste en 
	derniere position
	
		PARAMETRES:	previous_node: Un noeud précédent de la liste. 
		Cela peut ëtre n'importe lequel vu que la fonction va se placer 
		en bout de liste pour ajouter l'élément.
	
		VALEUR DE RETOUR: Renvoie la node nouvellement créé ou NULL si 
		l'allocation échoue.
*/

t_node	*ft_new_node(t_node *previous_node)
{
	t_node	*new_node;

	new_node = ft_create_node();
	if (new_node == NULL)
		return (NULL);
	if (previous_node == NULL)
		return (new_node);
	while (previous_node->next != NULL)
		previous_node = previous_node->next;
	previous_node->next = new_node;
	new_node->previous = previous_node;
	return (new_node);
}
