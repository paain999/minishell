/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:11:40 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/12 14:11:40 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	size_t			count;
	unsigned char	*buff;

	count = 0;
	buff = (unsigned char *)src;
	while (count < len)
		buff[count++] = c;
	return (src = buff);
}
/*int main(void)
{
    char    example[10] = "Holamundo";
    ft_memset(example + 1, '#', 4);
    printf("%s", example);
    return (0);
}*/
