/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:17 by marvin            #+#    #+#             */
/*   Updated: 2024/02/13 16:22:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouvu_ennemie(t_long *longe, int i)
{
	if (longe->en_y[i] != 0)
	{
		if (longe->map[longe->en_y[i] - 1][longe->en_x[i]] != '1')
		{
			if (longe->map[longe->en_y[i] - 1][longe->en_x[i]] != 'C')
			{
				if (longe->map[longe->en_y[i] - 1][longe->en_x[i]] != 'E')
				{
					mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
						longe->en02, (longe->en_x[i] * 64),
						((longe->en_y[i] - 1) * 64));
					mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
						longe->img_sol, (longe->en_x[i] * 64),
						(longe->en_y[i] * 64));
					longe->en_y[i]--;
				}
			}
		}
	}
}

void	mouvr_ennemie(t_long *longe, int i)
{
	if (longe->en_x[i] != 0)
	{
		if (longe->map[longe->en_y[i]][longe->en_x[i] - 1] != '1')
		{
			if (longe->map[longe->en_y[i]][longe->en_x[i] - 1] != 'C')
			{
				if (longe->map[longe->en_y[i]][longe->en_x[i] - 1] != 'E')
				{
					mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
						longe->en04, ((longe->en_x[i] - 1) * 64),
						((longe->en_y[i]) * 64));
					mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
						longe->img_sol, (longe->en_x[i] * 64),
						(longe->en_y[i] * 64));
					longe->en_x[i]--;
				}
			}
		}
	}
}

void	mouvd_ennemie(t_long *longe, int i)
{
	if (longe->en_y[i] < (longe->y / 64))
	{
		if (longe->map[longe->en_y[i] + 1][longe->en_x[i]] != '1')
		{
			if (longe->map[longe->en_y[i] + 1][longe->en_x[i]] != 'C')
			{
				if (longe->map[longe->en_y[i] + 1][longe->en_x[i]] != 'E')
				{
					mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
						longe->en01, (longe->en_x[i] * 64),
						((longe->en_y[i] + 1) * 64));
					mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
						longe->img_sol, (longe->en_x[i] * 64),
						(longe->en_y[i] * 64));
					longe->en_y[i]++;
				}
			}
		}
	}
}

void	mouvl_ennemie(t_long *longe, int i)
{
	if (longe->en_x[i] < (longe->x / 64))
	{
		if (longe->map[longe->en_y[i]][longe->en_x[i] + 1] != '1')
		{
			if (longe->map[longe->en_y[i]][longe->en_x[i] + 1] != 'C')
			{
				if (longe->map[longe->en_y[i]][longe->en_x[i] + 1] != 'E')
				{
					mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
						longe->en03, ((longe->en_x[i] + 1) * 64),
						((longe->en_y[i]) * 64));
					mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
						longe->img_sol, (longe->en_x[i] * 64),
						(longe->en_y[i] * 64));
					longe->en_x[i]++;
				}
			}
		}
	}
}

void	mouv_ennemie(t_long *longe)
{
	int	i;
	int	j;

	if (longe->ennemie_ok == 1)
	{
		i = 2;
		j = 0;
		free(longe->pen_x);
		free(longe->pen_y);
		longe->pen_x = malloc(sizeof(int) * ((longe->ennemie_lo / 3) + 1));
		longe->pen_y = malloc(sizeof(int) * ((longe->ennemie_lo / 3) + 1));
		longe->pen_x[(longe->ennemie_lo / 3)] = '\0';
		longe->pen_y[(longe->ennemie_lo / 3)] = '\0';
		while (i < longe->ennemie_lo)
		{
			mouv_ennemie03(longe, i, j);
			i += 3;
			j++;
		}
		mouv_ennemie02(longe);
	}
}
