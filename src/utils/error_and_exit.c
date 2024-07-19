/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:29:25 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/18 16:34:09 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	add_detail_quotes(char *cmd)
{
	if (ft_strncmp(cmd, "export", 7) == 0 || ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	return (0);
}

int	errmsg_cmd(char *cmd, char *detail, char *err_msg, int errn)
{
	char	*msg;
	int		detail_quotes;

	detail_quotes = add_detail_quotes(cmd);
	msg = ft_strdup("minishell: ");
	if (cmd != NULL)
	{
		msg = ft_strjoin_gnl(msg, cmd);
		msg = ft_strjoin_gnl(msg, ": ");
	}
	if (detail != NULL)
	{
		if (detail_quotes)
			msg = ft_strjoin_gnl(msg, "'");
		msg = ft_strjoin_gnl(msg, detail);
		if (detail_quotes)
			msg = ft_strjoin_gnl(msg, "'");
		msg = ft_strjoin_gnl(msg, ": ");
	}
	msg = ft_strjoin_gnl(msg, err_msg);
	ft_putendl_fd(msg, 2);
	free(msg);
	return (errn);
}

void	errmsg(char *errmsg, char *detail, int quotes)
{
	char	*msg;

	msg = ft_strdup("minishell: ");
	msg = ft_strjoin_gnl(msg, errmsg);
	if (quotes)
		msg = ft_strjoin_gnl(msg, " `");
	else
		msg = ft_strjoin_gnl(msg, ": ");
	msg = ft_strjoin_gnl(msg, detail);
	if (quotes)
		msg = ft_strjoin_gnl(msg, "'");
	ft_putendl_fd(msg, STDERR);
	free(msg);
}

void	ft_exit(t_minishell *minishell, int errn)
{
	if (minishell)
	{
		if (minishell->cmd && minishell->cmd->io_fds)
			close_fds(minishell->cmd);
		free_all(minishell);
	}
	exit(errn);
}
