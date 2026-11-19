/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:39:13 by tmoirand          #+#    #+#             */
/*   Updated: 2023/10/20 10:39:15 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_next_line(char *stati)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stati[i])
		return (NULL);
	while (stati[j] && stati[j] != '\n')
		j++;
	if (stati[j] == '\n')
		j++;
	line = (char *)malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	while (i < j)
	{
		line[i] = stati[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_ligne(char *stati)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stati[i] && stati[i] != '\n')
		i++;
	if (stati[i] == '\n')
		i++;
	while (stati[i + j])
		j++;
	line = (char *)malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (stati[i])
		line[j++] = stati[i++];
	line[j] = '\0';
	free (stati);
	stati = NULL;
	return (line);
}

char	*malloc_next_ligne(int fd, char *stati)
{
	char	*temp;
	int		t;

	t = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(stati, '\n') && t != 0)
	{
		t = read(fd, temp, BUFFER_SIZE);
		if (t < 0)
		{
			free (temp);
			return (NULL);
		}
		temp[t] = '\0';
		if (!stati)
			stati = ft_strdup("\0");
		stati = ft_strjoin(stati, temp);
	}
	free (temp);
	return (stati);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stati = NULL;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!ft_strchr(stati, '\n'))
	{
		stati = malloc_next_ligne(fd, stati);
	}
	line = get_next_next_line(stati);
	if (!stati || !(*stati))
	{
		free (stati);
		stati = NULL;
		return (NULL);
	}
	stati = next_ligne(stati);
	return (line);
}
