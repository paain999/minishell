/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:24:46 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/29 15:19:20 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		newlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s1 == '\0' && *s2 == '\0')
		return (ft_strdup(""));
	newlen = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * newlen + 1);
	if (!result)
		return (NULL);
	while (i <= newlen && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (i <= newlen && s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	free((char *)s1);
	return (result);
}
/* int main()
{
    char    *r;

    r = ft_srtjoin("Hola", " Mundo");

    printf("%s", r);
    free(r);
    return (0);
} */
