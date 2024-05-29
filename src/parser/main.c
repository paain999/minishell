/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:21 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/28 18:50:50 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char **get_paths(char **env)
{
	char	**paths;
	char	**envp;
	int		i;

	envp = env;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			*envp += 5;
			i = 0;
			paths = ft_split(*envp, ':');
		}
		envp++;
	}
	if (!*envp)
		return (NULL);
	return (paths);
}

t_minishell *init_shell(t_minishell *minishell, char **env)
{
	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	minishell->cmds = NULL;
	minishell->cmd_args = NULL;
	minishell->fd_in = 0;
	minishell->fd_out = 1;
	minishell->env = 
	minishell->paths = get_paths(env);
	return (minishell);
}

int	main(int ac, char **av, char **env)
{
	t_minishell *minishell;

	if (!env || !*env)
	{
		printf("Error: Minishell needs an environment\n");
		return (1);
	}
	if (ac > 1)
	{
		printf("Error: Minishell does not accept arguments\n");
		return (2);
	}
	return (0);
}
