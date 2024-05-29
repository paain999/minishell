/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpydarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:46:47 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/29 23:48:19 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cpdarr(char **arr)
{
	char	**cpy;
	int		len;

	len = -1;
	while (arr[++len])
		;
	cpy = malloc(sizeof(char *) * (len + 1));
	if (!cpy)
		return (NULL);
	len = -1;
	while (arr[++len])
		cpy[len] = ft_strdup(arr[len]);
	cpy[len] = (void*)0;
	return (cpy);
}
