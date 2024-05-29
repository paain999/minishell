	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:01:11 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/29 19:01:07 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../Libft/libft.h"

#define RST   "\033[0m"       // Restablecer el color
#define RED    "\033[0;31m"    // Rojo
#define GREEN   "\033[0;32m"    // Verde
#define YLW "\033[0;33m"   // Amarillo
#define BLUE    "\033[0;34m"    // Azul
#define PURPLE "\033[0;35m"    // Púrpura
#define CYAN    "\033[0;36m"    // Cian
#define WHITE  "\033[0;37m"    // Blanco

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
