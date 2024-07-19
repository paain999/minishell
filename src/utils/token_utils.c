/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:07:19 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/18 11:20:30 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*create_token(char *str, char *str_bckup, int type, int status)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = str;
	new->value_bckup = str_bckup;
	new->type = type;
	new->status = status;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void add_token(t_token **token, t_token *new_token)
{
	t_token *start;

	start = *token;
	if (!start)
	{
		*token = new_token;
		return ;
	}
	if (token && *token && new_token)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new_token;
		new_token->prev = start;
	}
}
