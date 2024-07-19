/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:01:11 by dajimene          #+#    #+#             */
/*   Updated: 2024/07/18 17:14:05 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>

# define RST "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# define PROMPT "\033[0;32mMinishell\033[0m:\033[0;34m~\033[0m$"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

enum				e_token_type
{
	SPACES = 1,
	WORD,
	VAR,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND,
	END
};

enum				e_quoting_type
{
	DEFAULT,
	SQUOTE,
	DQUOTE
};

typedef struct s_token
{
	char			*value;
	char			*value_bckup;
	bool			join;
	char			quote;
	int				type;
	int				status;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_io_fds
{
	char			*infile;
	char			*outfile;
	char			*heredoc_delimiter;
	bool			heredoc_quotes;
	int				fd_in;
	int				fd_out;
	int				stdin_backup;
	int				stdout_backup;
}					t_io_fds;

typedef struct s_cmd
{
	char			*cmd;
	char			*path;
	char			**args;
	bool			pipe_o;
	int				*pipe_fd;
	t_io_fds		*io_fds;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_minishell
{
	char			*user_prompt;
	t_token			*token;
	t_cmd			*cmd;
	char			*wdir;
	char			*oldpwd;
	char			quote_type;
	int				exit_status;
	char			**envp_cpy;
	pid_t			pid;
}					t_minishell;

// FREE AND EXIT FUNCTIONS
void				ft_exit(t_minishell *minishell, int errn);
void				free_all(t_minishell *minishell);
void				free_tokens(t_token **tokens);
int					close_fds(t_cmd *cmd);
void				errmsg(char *errmsg, char *detail, int quotes);
int					errmsg_cmd(char *cmd, char *detail, char *err_msg, int errn);

char				**get_paths(char **envp);
char				*get_env_var(char *var, char **envp);

int					tokenize(t_minishell *minishell);
t_token				*create_token(char *str, char *str_bckup, int type, int status);
void				add_token(t_token **tokens, t_token *new_token);
void				remove_quotes(t_minishell *minishell);
int					init_data(t_minishell *minishell, char **envp);

#endif
