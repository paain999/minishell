/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:18 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/31 18:13:57 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	ft_error_exit(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

static void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_all(t_minishell *minishell)
{
	if (!minishell)
		return ;
	if (minishell->envp_cpy)
		free_arr(minishell->envp_cpy);
	if (minishell->paths)
		free_arr(minishell->paths);
	if (minishell->prompt_str)
		free(minishell->prompt_str);
	if (minishell->username)
		free(minishell->username);
	if (minishell->pwd)
		free(minishell->pwd);
	if (minishell->homedir)
		free(minishell->homedir);
	if (minishell->shell)
		free(minishell->shell);
	free(minishell);
}

void	ft_exit(t_minishell *minishell, char *msg)
{
	free_all(minishell);
	if (msg)
		ft_error_exit(msg);
}

void	ft_secure_malloc(void **ptr, size_t size, size_t num)
{
	*ptr = malloc(size * num);
	if (!*ptr)
		ft_error_exit(RED "Malloc failed" RST);
}

