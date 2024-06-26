#include "../Libft/libft.h"
#include <stdio.h>

# define RST "\033[0m"
# define YLW "\033[0;33m"

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



static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	if (!tokens)
		return ;
	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->value);
		free(tmp);
	}
	tokens = NULL;
}

t_token	*create_token(char *value)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	if (!new_token->value)
		return (NULL);
	new_token->next = NULL;
	return (new_token);
}

void	add_token(t_token **tokens, t_token *new_token)
{
	t_token	*tmp;

	if (!*tokens)
		*tokens = new_token;
	else
	{
		tmp = *tokens;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
	}
}

static void handle_quotes(char **start, char **str, t_token **tokens)
{
	t_token *new_token;
	char	quote_type;

	new_token = NULL;
	*start = *str;
	quote_type = **str;
	(*str)++;
	while (**str && **str != quote_type)
		(*str)++;
	if (**str == quote_type)
	{
		while (**str && !is_space(**str))
			(*str)++;
		new_token = create_token(ft_substr(*start, 0, *str - *start));
		add_token(tokens, new_token);
		(*str)++;
	}
}

static void	handle_words(char **start, char **str, t_token **tokens)
{
	t_token *new_token;
	char	quote_type;

	new_token = NULL;
	*start = *str;
	if (**str == '"' || **str == '\'')
	{
		handle_quotes(start, str, tokens);
		return ;
	}
	while (**str && !is_space(**str) && **str != '\'' && **str != '"')
		(*str)++;
	if (**str == '"' || **str == '\'')
	{
		quote_type = **str;
		(*str)++;
		while (**str && **str != quote_type)
			(*str)++;
		while (**str && !is_space(**str))
			(*str)++;
	}
	new_token = create_token(ft_substr(*start, 0, *str - *start));
	add_token(tokens, new_token);
}

t_token	*tokenize(char *line, t_token *tokens)
{
	char	*start;
	char	*str;

	if (tokens)
		free_tokens(tokens);
	if (line[0] == '\0')
		return (NULL);
	line = ft_triminstr(line, " \t");
	if (!line)
		return (NULL);
	str = line;
	start = line;
	while (*str)
	{
		if (!is_space(*str))
			handle_words(&start, &str, &tokens);
		else
			str++;
	}
	return (tokens);
}

int	main(void)
{
	char	*line;
	t_token	*tokens;
	t_token	*tmp;

	tokens = NULL;
	tmp = NULL;
	line = ft_strdup("ech\"o hel\"lo \'world\'");
	tokens = tokenize(line, tokens);
	tmp = tokens;
	while (tmp)
	{
		printf("value: %s\n", tmp->value);
		tmp = tmp->next;
	}
	free_tokens(tokens);
	free(line);
	return (0);
}
