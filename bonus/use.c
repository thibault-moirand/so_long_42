/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:06 by marvin            #+#    #+#             */
/*   Updated: 2024/02/13 16:22:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *c1, const char *c2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while (i < n && c1[i] == c2[i] && c1[i] && c2[i])
		i++;
	if (i == n)
		return (0);
	return (1);
}

int	check_map_format(char *s, char **av)
{
	int	l;
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	close(fd);
	l = ft_strlen(s);
	if (l < 4)
		return (0);
	if (s[l - 1] != 'r' || s[l - 2] != 'e' || s[l - 3] != 'b'
		|| s[l - 4] != '.')
		return (0);
	return (1);
}

char	**tab_dup(char **tab, int start)
{
	char	**out;
	int		i;

	i = 0;
	while (tab[start + i])
		i++;
	out = malloc((i + 1) * sizeof(char *));
	i = start - 1;
	while (tab[++i])
		out[i - start] = ft_strdup(tab[i]);
	out[i - start] = NULL;
	return (out);
}

void	del_texture02(t_long *longe)
{
	mlx_destroy_image(longe->mlx_ptr, longe->img_21);
	mlx_destroy_image(longe->mlx_ptr, longe->img_22);
	mlx_destroy_image(longe->mlx_ptr, longe->img_23);
	mlx_destroy_image(longe->mlx_ptr, longe->img_24);
	mlx_destroy_image(longe->mlx_ptr, longe->img_25);
	mlx_destroy_image(longe->mlx_ptr, longe->img_26);
	mlx_destroy_image(longe->mlx_ptr, longe->img_27);
	mlx_destroy_image(longe->mlx_ptr, longe->img_28);
	mlx_destroy_image(longe->mlx_ptr, longe->img_29);
	mlx_destroy_image(longe->mlx_ptr, longe->img_30);
	mlx_destroy_image(longe->mlx_ptr, longe->img_31);
	mlx_destroy_image(longe->mlx_ptr, longe->img_32);
	mlx_destroy_image(longe->mlx_ptr, longe->img_33);
}

void	mur04(t_long *longe)
{
	if (longe->d1 == 1 && longe->d2 == 0 && longe->d3 == 1 && longe->d4 == 0
		&& longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_23,
			(longe->i * 64), (longe->j * 64));
	if (longe->d1 == 0 && longe->d2 == 1 && longe->d3 == 1 && longe->d4 == 0
		&& longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_21,
			(longe->i * 64), (longe->j * 64));
	if (longe->d1 == 0 && longe->d2 == 1 && longe->d3 == 0 && longe->d4 == 1
		&& longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_24,
			(longe->i * 64), (longe->j * 64));
	if (longe->d1 == 1 && longe->d2 == 0 && longe->d3 == 0 && longe->d4 == 1
		&& longe->g == 0 && longe->d == 0 && longe->b == 0 && longe->h == 0)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_22,
			(longe->i * 64), (longe->j * 64));
	if (longe->g == 1 && longe->d == 0 && longe->b == 0 && longe->h == 0
		&& longe->d3 == 1 && longe->d2 == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_31,
			(longe->i * 64), (longe->j * 64));
	if (longe->g == 0 && longe->d == 1 && longe->b == 0 && longe->h == 0
		&& longe->d1 == 1 && longe->d4 == 1)
		mlx_put_image_to_window(longe->mlx_ptr, longe->win_ptr, longe->img_32,
			(longe->i * 64), (longe->j * 64));
}
