/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:21 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/16 18:09:07 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_loop(t_minishell *minishell)
{
	while (1)
	{
		minishell->line = readline(PROMPT);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_minishell	minishell;

	(void)ac;
	(void)av;
	if (!envp || !*envp)
		ft_exit(NULL, EXIT_FAILURE);
	if (ac > 1)
		ft_exit(NULL, EXIT_FAILURE);
	ft_memset(&minishell, 0, sizeof(t_minishell));
	if (!init_data(&minishell, envp))
		ft_exit(NULL, EXIT_FAILURE);
	shell_loop(&minishell);
	ft_exit(&minishell, EXIT_SUCCESS);
	return (0);
}
