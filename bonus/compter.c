/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:36:44 by marvin            #+#    #+#             */
/*   Updated: 2024/02/21 14:36:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	compter02(t_long *longe, int i)
{
	if (longe->newnbr[i] == '4')
		mlx_put_image_to_window(longe->mlx_ptr,
			longe->win_ptr, longe->comp4,
			(i * 64), (0 * 64));
	else if (longe->newnbr[i] == '3')
		mlx_put_image_to_window(longe->mlx_ptr,
			longe->win_ptr, longe->comp3,
			(i * 64), (0 * 64));
	else if (longe->newnbr[i] == '5')
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->comp5,
			(i * 64), (0 * 64));
	else if (longe->newnbr[i] == '6')
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->comp6,
			(i * 64), (0 * 64));
	else if (longe->newnbr[i] == '7')
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->comp7,
			(i * 64), (0 * 64));
	else if (longe->newnbr[i] == '8')
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->comp8,
			(i * 64), (0 * 64));
	else if (longe->newnbr[i] == '9')
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->comp9,
			(i * 64), (0 * 64));
}

void	compter(t_long *longe)
{
	int	i;

	i = 0;
	longe->newnbr = ft_itoa(longe->nbr_move);
	while (longe->newnbr[i])
	{
		if (longe->newnbr[i] == '0')
			mlx_put_image_to_window(longe->mlx_ptr,
				longe->win_ptr, longe->comp0,
				(i * 64), (0 * 64));
		else if (longe->newnbr[i] == '1')
			mlx_put_image_to_window(longe->mlx_ptr,
				longe->win_ptr, longe->comp1,
				(i * 64), (0 * 64));
		else if (longe->newnbr[i] == '2')
			mlx_put_image_to_window(longe->mlx_ptr,
				longe->win_ptr, longe->comp2,
				(i * 64), (0 * 64));
		compter02(longe, i);
		i++;
	}
	free(longe->newnbr);
}
