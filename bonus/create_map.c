/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:44 by marvin            #+#    #+#             */
/*   Updated: 2024/02/13 16:22:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mur01(t_long *longe)
{
	if (longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_mur,
			(longe->i * 64), (longe->j * 64));
	if (longe->g == 0 && longe->d == 1 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_06,
			(longe->i * 64), (longe->j * 64));
	if (longe->g == 1 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_04,
			(longe->i * 64), (longe->j * 64));
	if (longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_02,
			(longe->i * 64), (longe->j * 64));
	if (longe->g == 0 && longe->d == 0 && longe->b == 1 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_08,
			(longe->i * 64), (longe->j * 64));
}

void	mur02(t_long *longe)
{
	if (longe->g == 1 && longe->d == 1 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_14,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 1 && longe->d == 1 && longe->b == 1 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_15,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 1 && longe->d == 1 && longe->b == 0 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_16,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 0 && longe->d == 0 && longe->b == 1 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_17,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 0 && longe->d == 1 && longe->b == 1 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_19,
			(longe->i * 64), (longe->j * 64));
}

void	mur03(t_long *longe)
{
	if ((longe->j + 1) <= ((longe->y / 64) - 1))
		if (longe->map[longe->j + 1][longe->i] != '1')
			longe->h++;
	if (longe->i - 1 >= 0 && longe->j - 1 >= 0)
		if (longe->map[longe->j - 1][longe->i - 1] != '1')
			longe->d1++;
	if ((longe->i + 1) <= ((longe->x / 64) - 1)
		&& (longe->j + 1) <= ((longe->y / 64) - 1))
		if (longe->map[longe->j + 1][longe->i + 1] != '1')
			longe->d2++;
	if (longe->j - 1 >= 0 && (longe->i + 1) <= ((longe->x / 64) - 1))
		if (longe->map[longe->j - 1][longe->i + 1] != '1')
			longe->d3++;
	if (longe->i - 1 >= 0 && (longe->j + 1) <= ((longe->y / 64) - 1))
		if (longe->map[longe->j + 1][longe->i - 1] != '1')
			longe->d4++;
}

void	mur(t_long *longe)
{
	longe->g = 0;
	longe->d = 0;
	longe->b = 0;
	longe->h = 0;
	longe->d1 = 0;
	longe->d2 = 0;
	longe->d3 = 0;
	longe->d4 = 0;
	if (longe->i - 1 >= 0)
		if (longe->map[longe->j][longe->i - 1] != '1')
			longe->g++;
	if ((longe->i + 1) <= ((longe->x / 64) - 1))
		if (longe->map[longe->j][longe->i + 1] != '1')
			longe->d++;
	if (longe->j - 1 >= 0)
		if (longe->map[longe->j - 1][longe->i] != '1')
			longe->b++;
	mur03(longe);
	mur01(longe);
	mur001(longe);
	mur02(longe);
	mur002(longe);
	mur04(longe);
	mur004(longe);
	mur05(longe);
}

void	mapcreat(t_long *longe)
{
	if (longe->map[longe->j][longe->i] == '1')
		mur(longe);
	if (longe->map[longe->j][longe->i] == '0')
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
			longe->img_sol, (longe->i * 64), (longe->j * 64));
	if (longe->map[longe->j][longe->i] == 'P')
	{
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
			longe->img_player, (longe->i * 64), (longe->j * 64));
		longe->player_x = longe->i;
		longe->player_y = longe->j;
	}
	if (longe->map[longe->j][longe->i] == 'C')
	{
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
			longe->img_loot, (longe->i * 64), (longe->j * 64));
		longe->map_loot++;
	}
	if (longe->map[longe->j][longe->i] == 'E')
	{
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
			longe->img_door, (longe->i * 64), (longe->j * 64));
		longe->end_x = longe->i;
		longe->end_y = longe->j;
	}
}
