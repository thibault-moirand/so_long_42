/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <tmoirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:18:39 by marvin            #+#    #+#             */
/*   Updated: 2024/03/01 13:30:51 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	recup_prev(t_long	*longe)
{
	longe->pplayer_x = longe->player_x;
	longe->pplayer_y = longe->player_y;
}

void	verif_dead2(t_long	*longe)
{
	int	i;

	i = 0;
	if (longe->pen_x[i] != '\0')
	{
		while (longe->pen_x[i])
		{
			if (longe->player_x == longe->pen_x[i]
				&& longe->player_y == longe->pen_y[i])
			{
				if (longe->pplayer_x == longe->en_x[i]
					&& longe->pplayer_y == longe->en_y[i])
					fin(longe, "nul tu est mort");
			}
			i++;
		}
	}
}

void	deal_key02(int key, t_long *longe)
{
	if (key == 119)
	{
		recup_prev(longe);
		mouvu(longe);
	}
	if (key == 97)
	{
		recup_prev(longe);
		mouvr(longe);
	}
	if (key == 115)
	{
		recup_prev(longe);
		mouvd(longe);
	}
	if (key == 100)
	{
		recup_prev(longe);
		mouvl(longe);
	}
}

void	recup_prev2(t_long	*longe, int j)
{
	longe->pen_x[j] = longe->en_x[j];
	longe->pen_y[j] = longe->en_y[j];
}

void	mouv_ennemie02(t_long *longe)
{
	int	j;

	j = 0;
	while (j < (longe->ennemie_lo / 3))
	{
		if (longe->en_pose[j] >= longe->en_pose_max[j] - 1)
			longe->en_pose[j] = 0;
		else
			longe->en_pose[j]++;
		j++;
	}
}
