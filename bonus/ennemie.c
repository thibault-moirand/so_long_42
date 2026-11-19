/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:25:07 by marvin            #+#    #+#             */
/*   Updated: 2024/02/16 13:25:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ennemie_taille(t_long *longe, int fd)
{
	char	*temp;
	int		la;

	longe->ennemie_lo = 0;
	longe->ennemie_la = 0;
	temp = "test";
	while (temp != NULL)
	{
		temp = NULL;
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		la = 0;
		while (temp[la] != '\n' && temp[la] != '\0')
			la++;
		if (la > longe->ennemie_la)
			longe->ennemie_la = la;
		longe->ennemie_lo++;
		free(temp);
	}
	free(temp);
}

void	set_ennemie(t_long *longe, int fd)
{
	int	k;

	k = 0;
	longe->ennemie = malloc(sizeof(char *) * (longe->ennemie_lo + 1));
	while (k < longe->ennemie_lo + 1)
	{
		longe->ennemie[k] = get_next_line(fd);
		k++;
	}
}

void	ennemie(t_long	*longe, char **av)
{
	int		fd;
	char	*enne;

	enne = ft_strjoin2(av[1], ".e");
	fd = open(enne, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		longe->ennemie_ok = 0;
		free (enne);
		return ;
	}
	ennemie_taille(longe, fd);
	close(fd);
	fd = open(enne, O_RDONLY);
	set_ennemie(longe, fd);
	free (enne);
	enne = NULL;
	close(fd);
}
