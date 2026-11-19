/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:27:38 by marvin            #+#    #+#             */
/*   Updated: 2024/02/16 11:27:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_texture04(t_long *longe)
{
	longe->player01 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/player01.xpm", &longe->t1, &longe->t2);
	longe->player02 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/player02.xpm", &longe->t1, &longe->t2);
	longe->player03 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/player03.xpm", &longe->t1, &longe->t2);
	longe->player04 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/player04.xpm", &longe->t1, &longe->t2);
	longe->en01 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/en03.xpm", &longe->t1, &longe->t2);
	longe->en02 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/en03.xpm", &longe->t1, &longe->t2);
	longe->en03 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/en01.xpm", &longe->t1, &longe->t2);
	longe->en04 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/en02.xpm", &longe->t1, &longe->t2);
	longe->comp0 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp0.xpm", &longe->t1, &longe->t2);
	longe->comp1 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp1.xpm", &longe->t1, &longe->t2);
}

void	create_texture05(t_long *longe)
{
	longe->comp2 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp2.xpm", &longe->t1, &longe->t2);
	longe->comp3 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp3.xpm", &longe->t1, &longe->t2);
	longe->comp4 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp4.xpm", &longe->t1, &longe->t2);
	longe->comp5 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp5.xpm", &longe->t1, &longe->t2);
	longe->comp6 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp6.xpm", &longe->t1, &longe->t2);
	longe->comp7 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp7.xpm", &longe->t1, &longe->t2);
	longe->comp8 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp8.xpm", &longe->t1, &longe->t2);
	longe->comp9 = mlx_xpm_file_to_image(longe->mlx_ptr,
			"sprites/comp9.xpm", &longe->t1, &longe->t2);
}

void	del_texture03(t_long *longe)
{
	mlx_destroy_image(longe->mlx_ptr, longe->player01);
	mlx_destroy_image(longe->mlx_ptr, longe->player02);
	mlx_destroy_image(longe->mlx_ptr, longe->player03);
	mlx_destroy_image(longe->mlx_ptr, longe->player04);
	mlx_destroy_image(longe->mlx_ptr, longe->en01);
	mlx_destroy_image(longe->mlx_ptr, longe->en02);
	mlx_destroy_image(longe->mlx_ptr, longe->en03);
	mlx_destroy_image(longe->mlx_ptr, longe->en04);
	mlx_destroy_image(longe->mlx_ptr, longe->comp0);
	mlx_destroy_image(longe->mlx_ptr, longe->comp1);
	mlx_destroy_image(longe->mlx_ptr, longe->comp2);
	mlx_destroy_image(longe->mlx_ptr, longe->comp3);
	mlx_destroy_image(longe->mlx_ptr, longe->comp4);
	mlx_destroy_image(longe->mlx_ptr, longe->comp5);
	mlx_destroy_image(longe->mlx_ptr, longe->comp6);
	mlx_destroy_image(longe->mlx_ptr, longe->comp7);
	mlx_destroy_image(longe->mlx_ptr, longe->comp8);
	mlx_destroy_image(longe->mlx_ptr, longe->comp9);
}

void	verif_dead(t_long *longe)
{
	int	i;

	i = 0;
	while (longe->en_x[i])
	{
		if (longe->player_x == longe->en_x[i]
			&& longe->player_y == longe->en_y[i])
			fin(longe, "nul tu est mort");
		i++;
	}
}

char	*ft_strjoin2(char *s1, char *s2)
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
	return (concat);
}
