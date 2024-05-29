/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:54:59 by dajimene          #+#    #+#             */
/*   Updated: 2022/12/20 13:57:07 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	lenght(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	char	*cast(long int nbr, int len, char *str, int isneg)
{
	if (nbr != 0)
		str = ft_calloc(len + 1, sizeof(char));
	else
		return (ft_strdup("0"));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	while (--len)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (isneg)
		str[0] = '-';
	else
		str[0] = nbr % 10 + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int			len;
	int			isneg;
	char		*str;
	long int	nbr;

	nbr = n;
	isneg = 0;
	len = lenght(nbr);
	str = 0;
	str = cast(nbr, len, str, isneg);
	if (!str)
		return (0);
	return (str);
}

/* int main()
{
	char *n;
	
	n = ft_itoa(9);
	printf("%s", n);
	return (0);
} */
