/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:18 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/18 17:03:52 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
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
	if (minishell)
	{
		if (minishell->user_prompt)
			free_ptr(minishell->user_prompt);
		if (minishell->wdir)
			free_ptr(minishell->wdir);
		if (minishell->oldpwd)
			free_ptr(minishell->oldpwd);
		if (minishell->envp_cpy)
			free_arr(minishell->envp_cpy);
		rl_clear_history();	
	}
}

