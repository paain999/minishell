/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:09:29 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/18 16:33:05 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	init_wdir(t_minishell *minishell)
{
	char	buff[4096];
	char	*wdir;

	wdir = getcwd(buff, 4096);
	minishell->wdir = ft_strdup(wdir);
	if (!minishell->wdir)
		return (0);
	if (get_env_var("OLDPWD=", minishell->envp_cpy))
	{
		minishell->oldpwd = get_env_var("OLDPWD=", minishell->envp_cpy);
		if (!minishell->oldpwd)
			return (0);
	}
	else
	{
		minishell->oldpwd = ft_strdup(wdir);
		if (!minishell->oldpwd)
			return (0);
	}
	return (1);
}

int init_data(t_minishell *minishell, char **envp)
{
	minishell->envp_cpy = ft_cpdarr(envp);
	if (!minishell->envp_cpy)
		return (0);
	if (!init_wdir(minishell))
		return (0);
	minishell->exit_status = 0;
	minishell->user_prompt = NULL;
	minishell->pid = -1;
	minishell->cmd = NULL;
	minishell->token = NULL;
	return (1);
}

void init_io(t_cmd *cmd)
{
	cmd->io_fds = malloc(sizeof(t_io_fds));
	if (!cmd->io_fds)
		return ;
	cmd->io_fds->infile = NULL;
	cmd->io_fds->outfile = NULL;
	cmd->io_fds->heredoc_delimiter = NULL;
	cmd->io_fds->heredoc_quotes = false;
	cmd->io_fds->fd_in = -1;
	cmd->io_fds->fd_out = -1;
	cmd->io_fds->stdin_backup = -1;
	cmd->io_fds->stdout_backup = -1;
}
