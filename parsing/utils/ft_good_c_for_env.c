/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_c_for_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:18:07 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:51:52 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_good_c_for_env(char c)
{
	if (ft_isdigit(c) == 1)
		return (1);
	else if (ft_isalpha(c) == 1)
		return (1);
	else if (c == '_')
		return (1);
	else
		return (-1);
}
