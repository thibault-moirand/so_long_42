/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:55 by marvin            #+#    #+#             */
/*   Updated: 2024/02/13 16:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_pose(t_long *longe)
{
	int	i;

	i = 1;
	if ((ft_strchr(longe->map[0], '0')) != NULL)
		return (1);
	if ((ft_strchr(longe->map[(longe->lo - 1)], '0')) != NULL)
		return (1);
	while (i < (longe->lo - 1))
	{
		if (longe->map[i][0] != '1' || longe->map[i][longe->la - 1] != '1')
			return (1);
		else if (ft_strlen(longe->map[i - 1]) != ft_strlen(longe->map[i]))
			return (1);
		i++;
	}
	if ((ft_strlen(longe->map[i - 1]) == ft_strlen(longe->map[i]))
		&& longe->map[i][ft_strlen(longe->map[i]) - 1] == '\n')
		return (0);
	if (ft_strlen(longe->map[i - 1]) != (ft_strlen(longe->map[i]) + 2))
		return (1);
	return (0);
}

int	verif_all_element(t_long *longe)
{
	while (++longe->jv < longe->lo - 1)
	{
		longe->iv = -1;
		while (++longe->iv < longe->la - 1)
		{
			if (longe->map[longe->jv][longe->iv] == 'E')
				longe->ev++;
			else if (longe->map[longe->jv][longe->iv] == 'C')
				longe->cv++;
			else if (longe->map[longe->jv][longe->iv] == 'P')
			{
				longe->player_x = longe->iv;
				longe->player_y = longe->jv;
				longe->pv++;
			}
			else if (longe->map[longe->jv][longe->iv] != '1' &&
					longe->map[longe->jv][longe->iv] != '0')
				return (1);
		}
	}
	if (longe->ev != 1 || longe->pv != 1 || longe->cv < 1)
		return (1);
	return (0);
}

void	tester_map(t_teste *teste, int player_x, int player_y)
{
	if (teste->map[player_y][player_x] == 'C')
		teste->c++;
	if (teste->map[player_y][player_x] == 'E')
	{
		teste->e++;
		teste->map[player_y][player_x] = '1';
		return ;
	}
	teste->map[player_y][player_x] = '1';
	if (teste->map[player_y - 1][player_x] != '1')
		tester_map(teste, player_x, player_y - 1);
	if (teste->map[player_y + 1][player_x] != '1')
		tester_map(teste, player_x, player_y + 1);
	if (teste->map[player_y][player_x - 1] != '1')
		tester_map(teste, player_x - 1, player_y);
	if (teste->map[player_y][player_x + 1] != '1')
		tester_map(teste, player_x + 1, player_y);
}

int	verif_valid(t_long *longe)
{
	t_teste	*teste;

	teste = malloc(sizeof(t_teste));
	teste->c = 0;
	teste->e = 0;
	teste->map_loot = longe->cv;
	teste->map = tab_dup(longe->map, 0);
	tester_map(teste, longe->player_x, longe->player_y);
	free_tab(teste->map);
	if (teste->e == 1)
	{
		if (teste->c == teste->map_loot)
		{
			free(teste);
			return (0);
		}
	}
	free(teste);
	return (1);
}

int	verif_map(t_long *longe)
{
	longe->jv = -1;
	longe->ev = 0;
	longe->cv = 0;
	longe->pv = 0;
	if (verif_pose(longe) == 1)
		return (1);
	if (verif_all_element(longe) == 1)
		return (1);
	if (verif_valid(longe) == 1)
		return (1);
	return (0);
}
