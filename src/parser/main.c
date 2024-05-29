/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:21 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/29 19:43:31 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_paths(char **envp)
{
	char	**paths;
	char	**env;
	int		i;

	env = envp;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			*env += 5;
			i = 0;
			paths = ft_split(*env, ':');
			if (!paths)
				return (NULL);
			while (paths[i])
			{
				paths[i] = ft_strjoin(paths[i], "/");
				i++;
			}
			break ;
		}
		env++;
	}
	if (!*env)
		return (NULL);
	return (paths);
}

void	init_shell(t_minishell *minishell, char **envp)
{
	minishell->cmds = NULL;
	minishell->cmd_args = NULL;
	minishell->fd_in = 0;
	minishell->fd_out = 1;
	minishell->envp_cpy = ft_cpy_arr(envp);
	if (!minishell->envp_cpy)
		ft_error_exit("Malloc failed");
	minishell->paths = get_paths(envp);
	if (!minishell->paths)
		ft_error_exit("Malloc failed");
}

int	main(int ac, char **av, char **envp)
{
	t_minishell	*minishell;
	int			i;

	(void)av;
	minishell = NULL;
	printf("argc: %d\n", ac);
	if (!envp || !*envp)
		ft_error_exit("No environment");
	if (ac > 1)
		ft_error_exit("No arguments allowed");
	minishell = malloc(sizeof(t_minishell));
	init_shell(minishell, envp);
	i = -1;
	while (minishell->envp_cpy[++i])
		printf(CYAN"envp_cpy[%d]: %s\n"RST, i, minishell->envp_cpy[i]);
	i = -1;
	while (minishell->paths[++i])
		printf(YLW"paths[%d]: %s\n"RST, i, minishell->paths[i]);
	return (0);
}
