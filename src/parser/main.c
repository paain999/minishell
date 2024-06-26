/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:21 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/20 17:39:12 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_loop(t_minishell *minishell)
{
	while (!minishell->exit_status)
	{
		minishell->line = readline(minishell->prompt_str);
		if (!minishell->line)
			ft_exit(minishell, RED "Readline failed" RST);
		if (minishell->line[0] != '\0')
			add_history(minishell->line);
		tokenize(minishell);
		if (ft_strcmp(minishell->line, "exit") == 0)
		{
			rl_clear_history();
			minishell->exit_status = 1;
		}
		free(minishell->line);
	}
}

void	init_shell(t_minishell *minishell, char **envp)
{
	//g_exit_code = 0;
	minishell->tokens = NULL;
	minishell->fd_in = dup(STDIN);
	minishell->fd_out = dup(STDOUT);
	minishell->quote_type = 0;
	minishell->envp_cpy = ft_cpdarr(envp);
	minishell->username = get_env_var("USER=", minishell->envp_cpy);
	minishell->prompt_str = ft_strjoin_gnl(ft_strjoin(GREEN,
				minishell->username),
			"@Minishell" WHITE ":" RST BLUE "~" WHITE "$ " RST);
	if (!minishell->prompt_str || !minishell->username || !minishell->envp_cpy)
		ft_exit(minishell, RED "Malloc failed" RST);
	minishell->pid = 0;
	minishell->exit_status = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_minishell	minishell;

	(void)ac;
	(void)av;
	if (!envp || !*envp)
		ft_error_exit(RED "No environment" RST);
	if (ac > 1)
		ft_error_exit(RED "No arguments allowed" RST);
	init_shell(&minishell, envp);
	shell_loop(&minishell);
	free_all(&minishell);
	return (0);
}
