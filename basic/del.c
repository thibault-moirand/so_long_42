/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:37 by marvin            #+#    #+#             */
/*   Updated: 2024/02/13 16:22:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	del_texture(t_long *longe)
{
	mlx_destroy_image(longe->mlx_ptr, longe->img_door);
	mlx_destroy_image(longe->mlx_ptr, longe->img_door02);
	mlx_destroy_image(longe->mlx_ptr, longe->img_01);
	mlx_destroy_image(longe->mlx_ptr, longe->img_02);
	mlx_destroy_image(longe->mlx_ptr, longe->img_03);
	mlx_destroy_image(longe->mlx_ptr, longe->img_04);
	mlx_destroy_image(longe->mlx_ptr, longe->img_06);
	mlx_destroy_image(longe->mlx_ptr, longe->img_07);
	mlx_destroy_image(longe->mlx_ptr, longe->img_08);
	mlx_destroy_image(longe->mlx_ptr, longe->img_09);
	mlx_destroy_image(longe->mlx_ptr, longe->img_10);
	mlx_destroy_image(longe->mlx_ptr, longe->img_11);
	mlx_destroy_image(longe->mlx_ptr, longe->img_12);
	mlx_destroy_image(longe->mlx_ptr, longe->img_13);
	mlx_destroy_image(longe->mlx_ptr, longe->img_14);
	mlx_destroy_image(longe->mlx_ptr, longe->img_15);
	mlx_destroy_image(longe->mlx_ptr, longe->img_16);
	mlx_destroy_image(longe->mlx_ptr, longe->img_17);
	mlx_destroy_image(longe->mlx_ptr, longe->img_18);
	mlx_destroy_image(longe->mlx_ptr, longe->img_19);
	mlx_destroy_image(longe->mlx_ptr, longe->img_20);
}

void	mlxall(t_long *longe)
{
	free_tab(longe->map);
	mlx_destroy_image(longe->mlx_ptr, longe->img_loot);
	mlx_destroy_image(longe->mlx_ptr, longe->img_player);
	mlx_destroy_image(longe->mlx_ptr, longe->img_mur);
	mlx_destroy_image(longe->mlx_ptr, longe->img_sol);
	del_texture(longe);
	del_texture02(longe);
	mlx_destroy_window(longe->mlx_ptr, longe->win_ptr);
	if (longe->mlx_ptr)
		mlx_destroy_display(longe->mlx_ptr);
	mlx_loop_end(longe->mlx_ptr);
	free (longe->mlx_ptr);
	free(longe);
	exit(0);
}

void	free_map(t_long *longe, char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		write(2, &a[i], 1);
		i++;
	}
	write(2, "\n", 1);
	free_tab(longe->map);
	free(longe);
	exit (0);
}

int	closew(t_long *longe)
{
	mlxall(longe);
	return (0);
}
