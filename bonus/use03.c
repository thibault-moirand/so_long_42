/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <tmoirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:43:40 by marvin            #+#    #+#             */
/*   Updated: 2024/03/04 10:29:11 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inite_var2(t_long *longe)
{
	if (longe->ennemie_ok == 1)
	{
		longe->en_x = malloc(sizeof(int) * ((longe->ennemie_lo / 3) + 1));
		longe->en_y = malloc(sizeof(int) * ((longe->ennemie_lo / 3) + 1));
		longe->en_pose = malloc(sizeof(int) * ((longe->ennemie_lo / 3) + 1));
		longe->en_pose_max = malloc(sizeof(int)
				* ((longe->ennemie_lo / 3) + 1));
		longe->pen_x = malloc(sizeof(int) * ((longe->ennemie_lo / 3) + 1));
		longe->pen_y = malloc(sizeof(int) * ((longe->ennemie_lo / 3) + 1));
		longe->pen_x[(longe->ennemie_lo / 3)] = '\0';
		longe->pen_y[(longe->ennemie_lo / 3)] = '\0';
		longe->pen_x[0] = '\0';
		longe->pen_y[0] = '\0';
	}
}

void	main02(char **av, t_long *longe)
{
	ennemie(longe, av);
	inite_var2(longe);
	inite_img(longe);
	create_map(longe);
	inite_ennemie(longe);
}

void	fin(t_long *longe, char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		write(2, &a[i], 1);
		i++;
	}
	write(2, "\n", 1);
	mlxall(longe);
}
