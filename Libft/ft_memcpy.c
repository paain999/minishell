/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:00:13 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/11 23:01:28 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*srcc;
	char		*dst;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	dst = (char *)dest;
	srcc = (const char *)src;
	while (n--)
		dst[n] = srcc[n];
	return (dest);
}
