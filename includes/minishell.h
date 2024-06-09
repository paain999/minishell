/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:01:11 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/07 12:23:16 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

# define RST "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

int			g_exit_code;

typedef struct s_minishell
{
	char	*line;
	char	*prompt_str;
	char	**cmds;
	int		exit_status;
	int		fd_in;
	int		fd_out;
	char	**envp_cpy;
	char	*username;
	pid_t	pid;
}			t_minishell;

void		ft_error_exit(char *msg);
char		**ft_cpy_arr(char **arr);
void		ft_exit(t_minishell *minishell, char *msg);
char		**get_paths(char **envp);
char		*get_env_var(char *var, char **envp);
void		free_all(t_minishell *minishell);
void		ft_secure_malloc(void **ptr, size_t size, size_t num);
void		parse_line(t_minishell *minishell);

#endif
