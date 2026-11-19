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

void	mouvu(t_long *longe)
{
	if (longe->player_y != 0)
	{
		if (longe->map[longe->player_y - 1][longe->player_x] != '1')
		{
			if (longe->map[longe->player_y - 1][longe->player_x] == 'C')
			{
				longe->player_loot++;
				longe->map[longe->player_y - 1][longe->player_x] = 0;
			}
			if (longe->map[longe->player_y - 1][longe->player_x] != 'E'
				|| longe->player_loot == longe->map_loot)
			{
				mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
					longe->img_sol, (longe->player_x * 64),
					(longe->player_y * 64));
				mouv_ennemie(longe);
				mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
					longe->player02, (longe->player_x * 64),
					((longe->player_y - 1) * 64));
				longe->player_y--;
				longe->nbr_move++;
			}
		}
	}
}

void	mouvr(t_long *longe)
{
	if (longe->player_x != 0)
	{
		if (longe->map[longe->player_y][longe->player_x - 1] != '1')
		{
			if (longe->map[longe->player_y][longe->player_x - 1] == 'C')
			{
				longe->player_loot++;
				longe->map[longe->player_y][longe->player_x - 1] = 0;
			}
			if (longe->map[longe->player_y][longe->player_x - 1] != 'E'
				|| longe->player_loot == longe->map_loot)
			{
				mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
					longe->img_sol, (longe->player_x * 64),
					(longe->player_y * 64));
				mouv_ennemie(longe);
				mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
					longe->player04, ((longe->player_x - 1) * 64),
					((longe->player_y) * 64));
				longe->player_x--;
				longe->nbr_move++;
			}
		}
	}
}

void	mouvd(t_long *longe)
{
	if (longe->player_y < (longe->y / 64))
	{
		if (longe->map[longe->player_y + 1][longe->player_x] != '1')
		{
			if (longe->map[longe->player_y + 1][longe->player_x] == 'C')
			{
				longe->player_loot++;
				longe->map[longe->player_y + 1][longe->player_x] = 0;
			}
			if (longe->map[longe->player_y + 1][longe->player_x] != 'E'
				|| longe->player_loot == longe->map_loot)
			{
				mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
					longe->img_sol, (longe->player_x * 64),
					(longe->player_y * 64));
				mouv_ennemie(longe);
				mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
					longe->player01, (longe->player_x * 64),
					((longe->player_y + 1) * 64));
				longe->player_y++;
				longe->nbr_move++;
			}
		}
	}
}

void	mouvl(t_long *longe)
{
	if (longe->player_x < (longe->x / 64))
	{
		if (longe->map[longe->player_y][longe->player_x + 1] != '1')
		{
			if (longe->map[longe->player_y][longe->player_x + 1] == 'C')
			{
				longe->player_loot++;
				longe->map[longe->player_y][longe->player_x + 1] = 0;
			}
			if (longe->map[longe->player_y][longe->player_x + 1] != 'E'
				|| longe->player_loot == longe->map_loot)
			{
				mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
					longe->img_sol, (longe->player_x * 64),
					(longe->player_y * 64));
				mouv_ennemie(longe);
				mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
					longe->player03, ((longe->player_x + 1) * 64),
					((longe->player_y) * 64));
				longe->player_x++;
				longe->nbr_move++;
			}
		}
	}
}

int	deal_key(int key, t_long *longe)
{
	if (key == 65307)
		fin(longe, "pk tu est partie");
	deal_key02(key, longe);
	compter(longe);
	if (longe->ennemie_ok == 1)
	{
		verif_dead(longe);
		verif_dead2(longe);
	}
	if (longe->player_loot == longe->map_loot)
	{
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
			longe->img_door02, (longe->end_x * 64), (longe->end_y * 64));
		if (longe->player_x == longe->end_x && longe->player_y == longe->end_y)
			fin(longe, "gg tu win");
	}
	return (0);
}
