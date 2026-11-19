/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_valid_en.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:59:25 by marvin            #+#    #+#             */
/*   Updated: 2024/03/01 16:59:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_en(t_long *longe)
{
	int	i;

	i = 0;
	while (longe->en_x[i])
	{
		if (longe->en_x[i] > 0 && longe->en_y[i] > 0
			&& longe->en_y[i] < longe->y - 1 && longe->en_x[i] < longe->x - 1)
			i++;
		else
			return (1);
	}
	i = 0;
	while (longe->en_x[i])
	{
		if (longe->map[longe->en_y[i]][longe->en_x[i]] == '0')
			i++;
		else
			return (1);
	}
	return (0);
}

void	free_all(t_long *longe, char *a)
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
