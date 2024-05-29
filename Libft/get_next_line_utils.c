/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:13:19 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/29 23:18:36 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join(char *dest, char * stash, char *buff)
{
	int	i;
	int	j;
	int newlen;

	i = 0;
	j = 0;
	newlen = ft_strlen(stash) + ft_strlen(buff);
	while (i <= newlen && stash[i])
	{
		dest[i] = stash[i];
		i++;
	}
	while (i <= newlen && buff[j])
		dest[i++] = buff[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_gnl(char *stash, char *buff)
{
	char	*result;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	result = (char *)malloc(1 + ft_strlen(stash) + ft_strlen(buff) * sizeof(char));
	if (!result)
		return (NULL);
	result = join(result, stash, buff);
	free(stash);
	return (result);
}

