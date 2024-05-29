	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:01:11 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/30 00:06:14 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../Libft/libft.h"

#define RST   "\033[0m"
#define RED    "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YLW "\033[0;33m"
#define BLUE    "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE  "\033[0;37m"

typedef struct s_minishell
{
	t_list	*cmds;
	char	*cmd_args;
	int		fd_in;
	int		fd_out;
	char	**envp_cpy;
	char	**paths;
}	t_minishell;

void	ft_error_exit(char *msg);
char	**ft_cpy_arr(char **arr);

#endif
