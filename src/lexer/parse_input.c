/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:11:30 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/19 14:06:56 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_space(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n'
			&& input[i] != '\v' && input[i] != '\f' && input[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	set_status(int status, char *str, int i)
{
	if (str[i] == '\'' && status == DEFAULT)
		status = SQUOTE;
	else if (str[i] == '\"' && status == DEFAULT)
		status = DQUOTE;
	else if (str[i] == '\'' && status == SQUOTE)
		status = DEFAULT;
	else if (str[i] == '\"' && status == DQUOTE)
		status = DEFAULT;
	return (status);
}

int	tokenize(t_minishell *minishell)
{
	int	i;
	int end;
	int start;
	int status;

	i = -1;
	start = 0;
	end = ft_strlen(minishell->user_prompt);
	status = DEFAULT;
	while (++i <= end)
	{
		status = set_status(status, minishell->user_prompt, i);
		if (status == DEFAULT)
			start = save_word_or_sep(&i, minishell->user_prompt, start, minishell);
 	}
	if (status != DEFAULT)
	{
		if (status == DQUOTE)
			errmsg("Unexpected EOF while looking for matching", "\"", 1);
		else if (status == SQUOTE)
			errmsg("Unexpected EOF while looking for matching", "'", 1);
		errmsg("syntax error", "unexpected end of file", 0);
		return (1);
	}
	return (0);
}

int	parse_input(t_minishell *minishell)
{
	if (minishell->user_prompt == NULL)
		return (0);
	else if (ft_strcmp(minishell->user_prompt, "\0") == 0)
		return (0);
	else if (is_space(minishell->user_prompt))
		return (1);
	add_history(minishell->user_prompt);
	if (tokenize(minishell) == 1)
		return (0);
	if (minishell->token->type == END)
		return (0);
	if (check_vars(&minishell->token) == 1)
		return (false);
	ft_expand(minishell, minsihell->token);
	handle_quotes(minishell);
	create_cmd(minishell, minishell->token);
	return (1);
}
