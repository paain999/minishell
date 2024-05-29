/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:51:42 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/16 00:00:20 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlen;
	char	*dest;
	char	*str;

	if (*s == '\0')
		return (ft_strdup(""));
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	strlen = ft_strlen(s);
	str = (char *)s + start;
	if (len > strlen && start == 0)
		len = strlen + 1;
	else if (len > strlen && start != 0)
		len = (strlen - start) + 1;
	else
		len++;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	else
		ft_strlcpy(dest, str, len);
	return (dest);
}
/*int main()
{
    char src[] = "hola";
 
    int m = 0;
    size_t n = 18446744073709551615;
 
    char* dest = ft_substr(src, m, n);
 
    printf("%s\n", dest);
 
    return 0;
}*/
