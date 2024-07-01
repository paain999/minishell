/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:17:33 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/01 19:55:38 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static void	handle_quotes(t_minishell *minishell, char **start, char **line)
{
	t_token	*new_token;

	new_token = NULL;
	*start = *line;
	minishell->quote_type = **line;
	(*line)++;
	while (**line && **line != minishell->quote_type)
		(*line)++;
	if (**line == minishell->quote_type)
	{
		while (**line && !is_space(**line))
			(*line)++;
		new_token = create_token(ft_substr(*start, 0, *line - *start));
		add_token(&minishell->tokens, new_token);
	}
}

static void	handle_words(t_minishell *minishell, char **start, char **line)
{
	t_token	*new_token;

	new_token = NULL;
	*start = *line;
	if (**line == '"' || **line == '\'')
		return(handle_quotes(minishell, start, line));
	while (**line && !is_space(**line) && **line != '\'' && **line != '"')
		(*line)++;
	if (**line == '"' || **line == '\'')
	{
		minishell->quote_type = **line;
		(*line)++;
		while (**line && **line != minishell->quote_type)
			(*line)++;
		while (**line && !is_space(**line))
			(*line)++;
	}
	new_token = create_token(ft_substr(*start, 0, *line - *start));
	add_token(&minishell->tokens, new_token);
}

void	tokenize(t_minishell *minishell)
{
	char	*start;
	char	*line;
	t_token	*tmp;

	if (minishell->tokens)
		free_tokens(&minishell->tokens);
	if (minishell->line[0] == '\0')
		return ;
	minishell->line = ft_triminstr(minishell->line, " \t");
	if (!minishell->line)
		ft_exit(minishell, RED "Malloc failed" RST);
	line = minishell->line;
	start = line;
	while (*line)
	{
		if (!is_space(*line))
			handle_words(minishell, &start, &line);
		else
			line++;
	}
	remove_quotes(minishell);
	tmp = minishell->tokens;
	while (tmp)
	{
		printf("Token: %s\n", tmp->value);
		tmp = tmp->next;
	}
}
