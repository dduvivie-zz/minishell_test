/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:14:50 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 03:18:45 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_redirection(t_token *token)
{
	if (token->type == OUTFILE || token->type == OUTFILE_HAP
		|| token->type == HEREDOC || token->type == INFILE)
	{
		return (1);
	}
	return (0);
}
