/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:06:54 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:27:30 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La fonction ft_concat_redir va concatener les différentes
	redirections si besoin.
	
	Si deux redirections se suivent alors ils les concatene
	si ils font partie des cas suivant:
		>>
		<<
		<>

	PARAMETRE: La structure data_parsing;

	VALEUR DE RETOUR:
		- Renvoie 0 si tout se passe bien
		- Renvoie -1 en cas d'erreur de malloc	
*/

int	ft_concat_infile(t_data_parsing *p, t_token *token)
{
	t_token	*next;

	if (token->next != NULL)
	{
		next = token->next;
		if (next->type == INFILE)
		{
			token->value = ft_realloc_add(token->value, '<');
			token->type = HEREDOC;
		}
		else if (next->type == OUTFILE)
			token->value = ft_realloc_add(token->value, '>');
		if (next->type == INFILE || next->type == OUTFILE)
			ft_delete_token_in_list(p, next);
		if (token->value == NULL)
			return (-1);
	}
	return (0);
}

int	ft_concat_outfile(t_data_parsing *p, t_token *token)
{
	t_token	*next;

	if (token->next != NULL)
	{
		next = token->next;
		if (next->type == OUTFILE)
		{
			token->value = ft_realloc_add(token->value, '>');
			token->type = OUTFILE_HAP;
			ft_delete_token_in_list(p, next);
			if (token->value == NULL)
				return (-1);
		}
	}
	return (0);
}

void	ft_change_redir_type(t_data_parsing *p)
{
	t_token	*token;

	token = p->first_token;
	while (1)
	{
		if (token->type == REDIRECTION)
		{
			if (token->value[0] == '>')
				token->type = OUTFILE;
			else
				token->type = INFILE;
		}
		if (token->next == NULL)
			break ;
		else
			token = token->next;
	}
}

int	ft_concat_redir(t_data_parsing *p)
{
	t_token	*token;

	token = p->first_token;
	ft_change_redir_type(p);
	while (1)
	{
		if (token->type == INFILE)
		{
			if (ft_concat_infile(p, token) == -1)
				return (-1);
		}
		if (token->type == OUTFILE)
		{
			if (ft_concat_outfile(p, token) == -1)
				return (-1);
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}
