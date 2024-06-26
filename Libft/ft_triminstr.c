/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triminstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:12:31 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/19 18:12:54 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_flag(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static	char	*ft_cpy(int len, int i, char *new, char const *s1)
{
	int	k;

	k = 0;
	while (i < len)
			new[k++] = s1[i++];
	new[k] = '\0';
	free((char *)s1);
	return (new);
}

char	*ft_triminstr(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*new;

	if (*s1 == '\0')
		return (ft_strdup(""));
	if (*set == '\0')
		return (ft_strdup(s1));
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_flag(set, s1[i]))
		i++;
	while (s1[len - 1] && ft_flag(set, s1[len - 1]))
		len--;
	if (len < i)
		len = i;
	new = ft_calloc((len - i) + 1, sizeof(char));
	if (new)
		return (ft_cpy(len, i, new, s1));
	return (NULL);
}
/*int main()
{
    char *r;

    r = ft_strtrim("ggggggg", "g");
    printf("%s", r);
    free(r);
    return (0);
}*/
