/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:11:45 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/16 20:11:44 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbrstr(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static	size_t	word_len(char const *s, char c, int count)
{
	int	i;

	i = 0;
	while (s[count] != c && s[count])
	{	
		i++;
		count++;
	}
	return (i);
}

static	char	**cpy(char **array, char const *s, char c, int nmstr)
{
	int		pos;
	int		count;
	size_t	len;

	pos = 0;
	count = 0;
	while (pos < nmstr)
	{
		while (s[count] == c)
			count++;
		len = word_len(s, c, count);
		array[pos] = ft_substr(s, count, len);
		count = count + len;
		pos++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int			nmstr;
	char		**array;

	nmstr = nbrstr(s, c);
	if (!s || !*s || !nmstr)
	{
		array = malloc(sizeof(char *) * 1);
		if (!array)
			return (NULL);
		*array = (void *)0;
		return (array);
	}
	array = malloc((nmstr + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	cpy(array, s, c, nmstr);
	array[nmstr] = 0;
	return (array);
}

/*int main()
{
    char **r;
	int i;

	i = 0;
    r = ft_split("Hola Mundo Virtual", ' ');
	while (r[i])
	{
		printf("%s ", r[i]);
		i++;
	}
	free(r);
    return (0);
}*/
