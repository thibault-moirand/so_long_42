/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <tmoirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:25 by marvin            #+#    #+#             */
/*   Updated: 2024/03/01 13:42:59 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_long *longe)
{
	while (1)
	{
		mapcreat(longe);
		longe->i++;
		if ((longe->i * 64) >= longe->x)
		{
			longe->i = 0;
			longe->j++;
		}
		if ((longe->j * 64) >= longe->y)
			break ;
	}
}

void	taille(t_long *longe, int fd)
{
	char	*temp;

	longe->lo = 1;
	longe->la = 0;
	temp = get_next_line(fd);
	while (temp[longe->la] != '\n')
		longe->la++;
	longe->la--;
	while (temp != NULL)
	{
		free(temp);
		temp = NULL;
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		longe->lo++;
	}
	free(temp);
}

void	setmap(t_long *longe, int fd)
{
	int	k;

	k = 0;
	longe->map = malloc(sizeof(char *) * (longe->lo + 1));
	while (k < longe->lo + 1)
	{
		longe->map[k] = get_next_line(fd);
		k++;
	}
}

int	main(int ac, char **av)
{
	t_long	*longe;
	int		fd;

	if (ac != 2)
		return (write(2, "Error\nav\n", 10), 0);
	if (!check_map_format(av[1], av))
		return (write(2, "Error\nmap .ber ou pas fichier\n", 31), 0);
	longe = malloc(sizeof(t_long));
	fd = open(av[1], O_RDONLY);
	taille(longe, fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	setmap(longe, fd);
	inite_var(longe);
	if (verif_map(longe) == 1)
		free_map(longe, "Error\nproblem avec la map");
	main02(av, longe);
	if (longe->ennemie_ok == 1)
		if (verif_en(longe) == 1)
			free_all(longe, "Error\nproblem avec les ennemie");
	mlx_hook(longe->win_ptr, 17, 0L, closew, longe);
	mlx_key_hook(longe->win_ptr, deal_key, longe);
	mlx_loop(longe->mlx_ptr);
	mlxall(longe);
}
