/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:39:00 by tmoirand          #+#    #+#             */
/*   Updated: 2023/10/20 10:39:02 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*concat;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	concat = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!concat)
		return (NULL);
	while (s1[++i])
		concat[i] = s1[i];
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	free (s1);
	return (concat);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*copie;
	int		i;

	i = 0;
	while (src[i])
		i++;
	copie = malloc(sizeof(char) * (i + 1));
	if (copie == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copie[i] = src[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}
