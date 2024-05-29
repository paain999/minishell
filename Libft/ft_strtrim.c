/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:33:14 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/21 16:42:33 by dajimene         ###   ########.fr       */
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

static	char	*ft(int len, int i, char *new, char const *s1)
{
	int	k;

	k = 0;
	while (i < len)
			new[k++] = s1[i++];
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
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
	{
		return (ft(len, i, new, s1));
	}
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
