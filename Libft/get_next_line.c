/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:10:30 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/30 21:38:58 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*cleanned;

	i = 0;
	cleanned = NULL;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0' || !stash[i])
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	cleanned = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!cleanned)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		cleanned[j++] = stash[i++];
	cleanned[j] = '\0';
	free(stash);
	stash = NULL;
	return (cleanned);
}

static char	*create_line(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (stash[i] && stash[i] != '\n')
		i++;
	i += (stash[i] == '\n');
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*add_to_stash(int fd, char *stash)
{
	char	*buff;
	int		readed;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed != 0)
	{
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((!stash && readed <= 0) || readed == -1)
		{
			free(buff);
			free(stash);
			stash = NULL;
			buff = NULL;
			return (NULL);
		}
		buff[readed] = '\0';
		if (readed > 0)
			stash = ft_strjoin_gnl(stash, buff);
	}
	free(buff);
	buff = NULL;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	stash[fd] = add_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = create_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	if (!ft_strlen(line))
	{
		free(stash[fd]);
		free(line);
		line = NULL;
		stash[fd] = NULL;
	}
	return (line);
}
