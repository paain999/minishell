/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:11:33 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/12 14:11:33 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	if (dest == src)
		return (dest);
	if (d > s)
	{
		while (size--)
			d[size] = s[size];
		return (dest);
	}
	while (size--)
		*d++ = *s++;
	return (dest);
}
/*int main()
{
    char dest[100] = "Loremipsun dolor sit a";
    if (dest != ft_memmove(dest, "consectetur", 5))
        write(1, "dest's adress was not returned\n", 31);
    write(1, dest, 22);
    return 0;
}*/
