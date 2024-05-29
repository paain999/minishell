/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:10:28 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/12 14:10:30 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, (num * size));
	return (p);
}
/* int main()
{
    char *str = (char *)ft_calloc(10, 10);
    printf("%d", *str);
    return (0);
} */
