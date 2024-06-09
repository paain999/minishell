/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:43:55 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/07 12:28:12 by dajimene         ###   ########.fr       */
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
			paths = ft_split(*env, ':');
			if (!paths)
				return (NULL);
			i = -1;
			while (paths[++i])
				paths[i] = ft_strjoin_gnl(paths[i], "/");
			break ;
		}
		env++;
	}
	if (!*env)
		return (NULL);
	return (paths);
}

char	*get_env_var(char *var, char **envp)
{
	char	**env;
	char	*ret;

	env = envp;
	while (*env)
	{
		if (ft_strncmp(*env, var, ft_strlen(var)) == 0)
		{
			ret = ft_strdup(*env + ft_strlen(var));
			if (!ret)
				return (NULL);
			return (ret);
		}
		env++;
	}
	return (NULL);
}
