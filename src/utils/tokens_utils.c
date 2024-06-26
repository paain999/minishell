/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:39:01 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/25 20:41:19 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

t_token	*create_token(char *value)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		ft_error_exit("Malloc failed");
	new_token->value = value;
	if (!new_token->value)
		ft_error_exit("Malloc failed");
	new_token->next = NULL;
	return (new_token);
}

void	add_token(t_token **tokens, t_token *new_token)
{
	t_token	*tmp;

	if (!*tokens)
		*tokens = new_token;
	else
	{
		tmp = *tokens;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
	}
}

static void	handle_quotes(t_minishell **minishell)
{
	int i;
	int len;

	i = -1;
	while ((*minishell)->tokens->value[i])
	{
		if ((*minishell)->tokens->value[i] == '"' || (*minishell)->tokens->value[i] == '\'')
		{
			(*minishell)->quote_type = (*minishell)->tokens->value[i];
			i++;
			while ((*minishell)->tokens->value[i] && (*minishell)->tokens->value[i] != (*minishell)->quote_type)
			{
				i++;
				len++;
			}
		}
		else
			i++;
	}
}

void	remove_quotes(t_minishell *minishell)
{
	t_token *first;
	char	*quote;

	first = minishell->tokens;
	while (minishell->tokens)
	{
		if (minishell->tokens->value[0] == '"' || minishell->tokens->value[0] == '\'')
		{
			quote[0] = minishell->tokens->value[0];
			minishell->tokens->value = ft_triminstr(minishell->tokens->value, quote);
			if (!minishell->tokens->value)
				ft_error_exit("Malloc failed");
		}
		else
		{
			handle_quotes(&minishell);
			minishell->tokens = minishell->tokens->next;
		}
	}
}
