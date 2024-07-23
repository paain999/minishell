/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:08:03 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/19 15:34:39 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_vars(t_token **tokens)
{
	t_token *tmp;

	temp = *tokens;
	if (tmp->type == PIPE)
	{
		errmsg("syntax error near unexpected token", temp->value);
		return (1);
	}
}
