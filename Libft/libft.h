/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:02:58 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/19 18:14:35 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
//# include <stdio.h>

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1
# endif

// CHARACTER MANIPULATION
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// MEMORY MANIPULATION
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);

// NUMBERS MANIPULATION 
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

// STRINGS MANIPULATION
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, char *src, size_t len);
size_t	ft_strlcat(char *dest, const char *scr, size_t destsize);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_triminstr(char const *s1, char const *set);

// PRINT
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// LIST
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	
}					t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// GET_NEXT_LINE
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);

// ARRAY MANIPULATION

char	**ft_cpdarr(char **arr);
void	ft_arrpush(void ***arr, void *new_element);
int		ft_arrlen(void **arr);

#endif
