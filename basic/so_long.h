/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:11 by marvin            #+#    #+#             */
/*   Updated: 2024/02/13 16:22:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_long
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_mur;
	void	*img_door;
	void	*img_door02;
	void	*img_01;
	void	*img_02;
	void	*img_03;
	void	*img_04;
	void	*img_06;
	void	*img_07;
	void	*img_08;
	void	*img_09;
	void	*img_10;
	void	*img_11;
	void	*img_12;
	void	*img_13;
	void	*img_14;
	void	*img_15;
	void	*img_16;
	void	*img_17;
	void	*img_18;
	void	*img_19;
	void	*img_20;
	void	*img_21;
	void	*img_22;
	void	*img_23;
	void	*img_24;
	void	*img_25;
	void	*img_26;
	void	*img_27;
	void	*img_28;
	void	*img_29;
	void	*img_30;
	void	*img_31;
	void	*img_32;
	void	*img_33;
	void	*img_sol;
	void	*img_player;
	void	*img_loot;
	char	**map;
	int		i;
	int		j;
	int		t1;
	int		t2;
	int		x;
	int		y;
	int		la;
	int		lo;
	int		player_x;
	int		player_y;
	int		nbr_player;
	int		player_loot;
	int		map_loot;
	int		end_x;
	int		end_y;
	int		nbr_end;
	int		nbr_move;
	int		iv;
	int		jv;
	int		ev;
	int		cv;
	int		pv;
	int		g;
	int		d;
	int		b;
	int		h;
	int		d1;
	int		d2;
	int		d3;
	int		d4;
}	t_long;

typedef struct s_teste
{
	int		c;
	int		e;
	int		map_loot;
	char	**map;
}	t_teste;

char	*get_next_line(int fd);
void	printnbr(int n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *c1, const char *c2, size_t n);
char	*ft_strdup(const char *src);
int		check_map_format(char *s, char **av);
char	**tab_dup(char **tab, int start);
void	del_texture02(t_long *longe);
void	mur04(t_long *longe);

void	mouvu(t_long *longe);
void	mouvr(t_long *longe);
void	mouvd(t_long *longe);
void	mouvl(t_long *longe);
int		deal_key(int key, t_long *longe);

void	free_tab(char **tab);
void	del_texture(t_long *longe);
void	mlxall(t_long *longe);
void	free_map(t_long *longe, char *a);
int		closew(t_long *longe);

void	mur01(t_long *longe);
void	mur02(t_long *longe);
void	mur03(t_long *longe);
void	mur(t_long *longe);
void	mapcreat(t_long *longe);

char	**tab_dup(char **tab, int start);
int		verif_pose(t_long *longe);
int		verif_all_element(t_long *longe);
int		verif_valid(t_long *longe);
int		verif_map(t_long *longe);

void	inite_var(t_long *longe);
void	create_texture(t_long *longe);
void	inite_img(t_long *longe);

void	create_map(t_long *longe);
void	taille(t_long *longe, int fd);
void	setmap(t_long *longe, int fd);

void	mur001(t_long *longe);
void	mur002(t_long *longe);
void	mur004(t_long *longe);
void	mur05(t_long *longe);

#endif