/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <tmoirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:29 by marvin            #+#    #+#             */
/*   Updated: 2024/03/01 13:27:33 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inite_var(t_long *longe)
{
	longe->nbr_player = 0;
	longe->nbr_end = 0;
	longe->nbr_move = 0;
	longe->player_loot = 0;
	longe->map_loot = 0;
	longe->t2 = 64;
	longe->t1 = 64;
	longe->i = 0;
	longe->j = 0;
	longe->x = (longe->la * 64);
	longe->y = (longe->lo * 64);
	longe->ennemie_ok = 1;
}

void	create_texture02(t_long *longe)
{
	longe->img_25 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/25.xpm", &longe->t1, &longe->t2);
	longe->img_26 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/26.xpm", &longe->t1, &longe->t2);
	longe->img_27 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/27.xpm", &longe->t1, &longe->t2);
	longe->img_28 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/28.xpm", &longe->t1, &longe->t2);
	longe->img_29 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/29.xpm", &longe->t1, &longe->t2);
	longe->img_30 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/30.xpm", &longe->t1, &longe->t2);
	longe->img_31 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/31.xpm", &longe->t1, &longe->t2);
	longe->img_32 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/32.xpm", &longe->t1, &longe->t2);
	longe->img_33 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/33.xpm", &longe->t1, &longe->t2);
	longe->img_23 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/23.xpm", &longe->t1, &longe->t2);
	longe->img_24 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/24.xpm", &longe->t1, &longe->t2);
}

void	create_texture03(t_long *longe)
{
	longe->img_11 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/11.xpm", &longe->t1, &longe->t2);
	longe->img_12 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/12.xpm", &longe->t1, &longe->t2);
	longe->img_13 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/13.xpm", &longe->t1, &longe->t2);
	longe->img_14 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/14.xpm", &longe->t1, &longe->t2);
	longe->img_15 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/15.xpm", &longe->t1, &longe->t2);
	longe->img_16 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/16.xpm", &longe->t1, &longe->t2);
	longe->img_17 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/17.xpm", &longe->t1, &longe->t2);
	longe->img_18 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/18.xpm", &longe->t1, &longe->t2);
	longe->img_19 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/19.xpm", &longe->t1, &longe->t2);
	longe->img_20 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/20.xpm", &longe->t1, &longe->t2);
}

void	create_texture(t_long *longe)
{
	longe->img_01 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/01.xpm", &longe->t1, &longe->t2);
	longe->img_02 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/02.xpm", &longe->t1, &longe->t2);
	longe->img_03 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/03.xpm", &longe->t1, &longe->t2);
	longe->img_04 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/04.xpm", &longe->t1, &longe->t2);
	longe->img_06 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/06.xpm", &longe->t1, &longe->t2);
	longe->img_07 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/07.xpm", &longe->t1, &longe->t2);
	longe->img_08 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/08.xpm", &longe->t1, &longe->t2);
	longe->img_09 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/09.xpm", &longe->t1, &longe->t2);
	longe->img_10 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/10.xpm", &longe->t1, &longe->t2);
}

void	inite_img(t_long *longe)
{
	longe->mlx_ptr = mlx_init();
	longe->win_ptr = mlx_new_window(longe->mlx_ptr,
			longe->x, longe->y, "so long");
	longe->img_mur = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/mur.xpm", &longe->t1, &longe->t2);
	longe->img_sol = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/sol.xpm", &longe->t1, &longe->t2);
	longe->img_player = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/player01.xpm", &longe->t1, &longe->t2);
	longe->img_loot = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/chest_01.xpm", &longe->t1, &longe->t2);
	longe->img_door = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/door.xpm", &longe->t1, &longe->t2);
	longe->img_door02 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/door02.xpm", &longe->t1, &longe->t2);
	longe->img_21 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/21.xpm", &longe->t1, &longe->t2);
	longe->img_22 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/22.xpm", &longe->t1, &longe->t2);
	create_texture(longe);
	create_texture02(longe);
	create_texture03(longe);
	create_texture04(longe);
	create_texture05(longe);
}
