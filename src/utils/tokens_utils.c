/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:39:01 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/01 19:57:13 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

static int get_len(char *str)
{
	int	len;
	char quote;

	len = 0;
	while (*str)
	{
		if (*str != '"' && *str != '\'')
			len++;
		else
		{
			quote = *str;
			str++;
			while (*str && *str != quote)
			{
				len++;
				str++;
			}
		}
		str++;
	}
	return (len);
}

static char *create_new_value(char *str, char quote)
{
	char	*new_value;
	int		len;

	len = get_len(str);
	new_value = malloc(sizeof(char) * (len + 1));
	if (!new_value)
		ft_error_exit("Malloc failed");
	len = 0;
	while (*str)
	{
		if (*str != '"' && *str != '\'')
			new_value[len++] = *str;
		else
		{
			quote = *str;
			str++;
			while (*str && *str != quote)
			{
				new_value[len++] = *str;
				str++;
			}
		}
		str++;
	}
	new_value[len] = '\0';
	free(str);
	return (new_value);
}

void	remove_quotes(t_minishell *minishell)
{
	t_token *tmp;
	char quote;

	tmp = minishell->tokens;
	quote = 0;
	while (tmp)
	{
		tmp->value = create_new_value(tmp->value, quote);
		tmp = tmp->next;
	}
}
