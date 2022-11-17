/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambiguous_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:02:41 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:20:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La fonction ft_ambigous redirect va verfier si une redirection ne pointe pas
	vers une variable d'environement vide.

	PARAMETRES: La structure data_parsing

	VALEUR DE RETOUR:
		- Renvoie 0 si tout va bien.
		- Renvoie -1 en cas d'erreur de malloc
		- Renvoie -2 si une variable vide est trouvée
*/

int	ft_check_env_ambiguous(t_data_parsing *p, t_token *token)
{
	char	*value;
	int		i;
	int		exit_code;

	i = 1;
	while (token->value[i])
	{
		if (ft_good_c_for_env(token->value[i]) == -1)
			return (0);
		i++;
	}
	exit_code = ft_get_env_value(&token->value[1], &value, p->envp);
	if (exit_code == -1)
		return (-1);
	free (value);
	if (exit_code == 0)
		return (-2);
	return (0);
}

int	ft_condition_ambigous(t_token *token)
{
	if (token->next->type == WORDS && token->next->value[0] == '$'
		&& token->next->value[1])
		return (1);
	return (0);
}

int	ft_ambiguous_redirect(t_data_parsing *p)
{
	t_token	*token;
	int		exit_code;

	token = p->first_token;
	while (1)
	{
		if (ft_is_redirection(token) == 1 && token->type != HEREDOC)
		{
			if (token->next != NULL)
			{
				if (ft_condition_ambigous(token) == 1)
				{
					exit_code = ft_check_env_ambiguous(p, token->next);
					if (exit_code == -2)
						return (ft_err_pars_ambiguous(p, token->next, -2));
					if (exit_code == -1)
						return (-1);
				}
			}
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}
