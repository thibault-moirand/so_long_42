/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inite_ennemie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <tmoirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:11:19 by marvin            #+#    #+#             */
/*   Updated: 2024/03/04 10:28:39 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	retur;
	int	signe;

	i = 0;
	retur = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1 ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		retur = (retur * 10) + (str[i] - '0');
		i++;
	}
	return (signe * retur);
}

size_t	ft_strlen02(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i--;
	return (i);
}

void	mouv_ennemie03(t_long *longe, int i, int j)
{
	if (longe->ennemie[i][longe->en_pose[j]] == 'u')
	{
		recup_prev2(longe, j);
		mouvu_ennemie(longe, j);
	}
	if (longe->ennemie[i][longe->en_pose[j]] == 'l')
	{
		recup_prev2(longe, j);
		mouvr_ennemie(longe, j);
	}
	if (longe->ennemie[i][longe->en_pose[j]] == 'd')
	{
		recup_prev2(longe, j);
		mouvd_ennemie(longe, j);
	}
	if (longe->ennemie[i][longe->en_pose[j]] == 'r')
	{
		recup_prev2(longe, j);
		mouvl_ennemie(longe, j);
	}
}

void	set_var(t_long	*longe, int j)
{
	longe->en_x[j] = '\0';
	longe->en_y[j] = '\0';
	longe->en_pose[j] = '\0';
	longe->en_pose_max[j] = '\0';
}

void	inite_ennemie(t_long	*longe)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (longe->ennemie_ok == 1)
	{
		while (longe->ennemie[i])
		{
			longe->en_x[j] = ft_atoi(longe->ennemie[i]);
			i++;
			longe->en_y[j] = ft_atoi(longe->ennemie[i]);
			i++;
			longe->en_pose[j] = 0;
			longe->en_pose_max[j] = ft_strlen02(longe->ennemie[i]);
			i++;
			mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr,
				longe->en01, (longe->en_x[j] * 64),
				((longe->en_y[j]) * 64));
			j++;
		}
		set_var(longe, j);
	}
}
