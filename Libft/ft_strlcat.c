/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:05 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/12 14:32:05 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	count;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size <= destlen)
		return (srclen + size);
	count = destlen;
	while (*src != '\0' && count < (size - 1))
		*(dest + count++) = *src++;
	*(dest + count) = '\0';
	return (destlen + srclen);
}
/* int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    char buffer[16];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,16);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > 16 )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
} */
