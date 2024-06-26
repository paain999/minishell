/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:01:11 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/25 14:20:31 by dajimene         ###   ########.fr       */
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

# define STDIN 0
# define STDOUT 1
# define STDERR 2

enum					e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
};

typedef struct s_token
{
	char				*value;
	enum e_token_type	type;
	struct s_token		*next;
}						t_token;

typedef struct s_minishell
{
	char				*line;
	char				*prompt_str;
	t_token				*tokens;
	char				quote_type;
	int					exit_status;
	int					fd_in;
	int					fd_out;
	char				**envp_cpy;
	char				*username;
	pid_t				pid;
}						t_minishell;

// FREE AND EXIT FUNCTIONS
void					ft_error_exit(char *msg);
void					ft_exit(t_minishell *minishell, char *msg);
void					free_all(t_minishell *minishell);
void					free_tokens(t_token **tokens);

char					**get_paths(char **envp);
char					*get_env_var(char *var, char **envp);

void					tokenize(t_minishell *minishell);
t_token					*create_token(char *value);
void					add_token(t_token **tokens, t_token *new_token);
int						is_space(char c);

#endif
