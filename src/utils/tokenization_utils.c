/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:05:47 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/18 16:25:11 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int set_type(char *str, int i)
{
	if ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		return (SPACES);
	else if (str[i] == '|')
		return (PIPE);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (HEREDOC);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (APPEND);
	else if (str[i] == '>')
		return (TRUNC);
	else if (str[i] == '<')
		return (INPUT);
	else if (str[i] == '\0')
		return (END);
	else
		return (0);
}

int add_word(t_token **token, char *str, int index, int start)
{
	int	i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (1);
	while (start < index)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	add_token(token, create_token(word, ft_strdup(word), WORD, DEFAULT));
	return (0);
}

int add_sep(t_token **token, char *str, int index, int type)
{
	int i;
	char *sep;

	i = 0;
	if (type == APPEND || type == HEREDOC)
	{
		sep = malloc(sizeof(char) * 3);
		if (!sep)
			return (1);
		while (i < 2)
			sep[i++] = str[index++];
		sep[i] = '\0';
		add_token(token, create_token(sep, NULL, type, DEFAULT));
	}
	else
	{
		sep = malloc(sizeof(char) * 2);
		if (!sep)
			return (1);
		while (i < 1)
			sep[i++] = str[index++];
		sep[i] = '\0';
		add_token(token, create_token(sep, NULL, type, DEFAULT));
	}
	return (0);
}
int save_word_or_sep(int *i, char *str, int start, t_minishell *minishell)
{
	int	type;

	type = set_type(str, (*i));
	if (type)
	{
		if ((*i) != 0 && set_type(str, (*i) - 1) == 0)
			add_word(&minishell->token, str, (*i), start);
		if (type == APPEND || type == HEREDOC || type == TRUNC || type == INPUT || type == PIPE || type == END)
		{
			add_sep(&minishell->token, str, (*i), type);
			if (type == APPEND || type == HEREDOC)
				(*i)++;
		}
		start = (*i) + 1;
	}
	return (start);
}