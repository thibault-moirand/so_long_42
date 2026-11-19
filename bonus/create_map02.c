/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:16:06 by marvin            #+#    #+#             */
/*   Updated: 2024/02/14 17:16:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mur001(t_long *longe)
{
	if (longe->d1 == 0 && longe->d2 == 0 && longe->d3 == 1 && longe->d4 == 0
		&& longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_09,
			(longe->i * 64), (longe->j * 64));
	if (longe->d1 == 1 && longe->d2 == 0 && longe->d3 == 0 && longe->d4 == 0
		&& longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_07,
			(longe->i * 64), (longe->j * 64));
	if (longe->d1 == 0 && longe->d2 == 1 && longe->d3 == 0 && longe->d4 == 0
		&& longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_03,
			(longe->i * 64), (longe->j * 64));
	if (longe->d1 == 0 && longe->d2 == 0 && longe->d3 == 0 && longe->d4 == 1
		&& longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_01,
			(longe->i * 64), (longe->j * 64));
}

void	mur002(t_long *longe)
{
	if (longe->g == 1 && longe->d == 0 && longe->b == 1 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_18,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 1 && longe->d == 1 && longe->b == 1 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_20,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 1 && longe->d == 0 && longe->b == 1 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_11,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 1 && longe->d == 0 && longe->b == 0 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_13,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 0 && longe->d == 1 && longe->b == 1 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_10,
			(longe->i * 64), (longe->j * 64));
	else if (longe->g == 0 && longe->d == 1 && longe->b == 0 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_12,
			(longe->i * 64), (longe->j * 64));
}

void	mur004(t_long *longe)
{
	if (longe->g == 0 && longe->d == 0 && longe->b == 1 && longe->h == 0
		&& longe->d2 == 1 && longe->d4 == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_29,
			(longe->i * 64), (longe->j * 64));
	if (longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 1
		&& longe->d1 == 1 && longe->d3 == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_30,
			(longe->i * 64), (longe->j * 64));
	if (longe->d4 == 1 && longe->d3 == 0 && longe->g == 1 && longe->d == 0
		&& longe->b == 0 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_26,
			(longe->i * 64), (longe->j * 64));
	if (longe->d1 == 1 && longe->d2 == 0 && longe->g == 1 && longe->d == 0
		&& longe->b == 1 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_25,
			(longe->i * 64), (longe->j * 64));
	if (longe->d2 == 1 && longe->d1 == 0 && longe->g == 0 && longe->d == 1
		&& longe->b == 0 && longe->h == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_27,
			(longe->i * 64), (longe->j * 64));
	if (longe->d3 == 1 && longe->d4 == 0 && longe->g == 0 && longe->d == 1
		&& longe->b == 1 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_28,
			(longe->i * 64), (longe->j * 64));
}

void	mur05(t_long *longe)
{
	if (longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0
		&& longe->d1 == 1 && longe->d2 == 1 && longe->d3 == 1 && longe->d4 == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_33,
			(longe->i * 64), (longe->j * 64));
}
