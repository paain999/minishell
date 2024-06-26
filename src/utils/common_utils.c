/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:18 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/24 14:12:58 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error_exit(char *msg)
{
	ft_putstr_fd("Error: ", STDERR);
	ft_putstr_fd(msg, STDERR);
	ft_putstr_fd("\n", STDERR);
	exit(1);
}

static void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

void	free_tokens(t_token **tokens)
{
	t_token	*tmp;

	if (!*tokens)
		return ;
	while (*tokens)
	{
		tmp = *tokens;
		*tokens = (*tokens)->next;
		free(tmp->value);
		free(tmp);
	}
	tokens = NULL;
}

void	free_all(t_minishell *minishell)
{
	if (!minishell)
		return ;
	if (minishell->envp_cpy)
		free_arr(minishell->envp_cpy);
	if (minishell->prompt_str)
		free(minishell->prompt_str);
	if (minishell->username)
		free(minishell->username);
	if (minishell->tokens)
		free_tokens(&minishell->tokens);
}

void	ft_exit(t_minishell *minishell, char *msg)
{
	free_all(minishell);
	if (msg)
		ft_error_exit(msg);
}
