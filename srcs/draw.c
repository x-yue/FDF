/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:54:43 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/21 14:03:44 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int		ft_map(void)
{
	t_draw	d;

	d.inc = 10;
	d.index = 100;
	d.ini = 100;
	d.map_hor = 809;
	d.map_ver = 500;
	d.mlx_ptr = mlx_init();// open a screen 
	d.win_ptr = mlx_new_window(d.mlx_ptr, d.map_hor, d.map_ver, "New Window");
	d.ver = d.ini;
	while (d.ver <= d.map_ver - d.index + d.inc / 2)
	{
	d.hor = d.ini;
	mlx_pixel_put(d.mlx_ptr, d.win_ptr, d.hor, d.ver, 0xFFFFFF); //
		while (d.hor <= d.map_hor - d.index + d.inc / 2)
		{
			mlx_pixel_put(d.mlx_ptr, d.win_ptr, d.hor, d.ver, 0xFFFFFF); //
			d.hor = d.hor + d.inc;
		}
		d.ver = d.ver + d.inc;
		d.ini++;
	}
	mlx_key_hook(d.win_ptr, deal_key, (void *)0);
	mlx_loop(d.mlx_ptr); //where to draw and gestion des evenements
	return (0);
}

int		hor_map(int **table)
{
	int hor_map;

	hor_map = ft_size_hor(table) * 3 + ft_max_int(table) * 3 + 10;
	if (hor_map > 1280)
		hor_map = 1280;
	if (hor_map < 150)
		hor_map = 150;
	return (hor_map);
}

int		ver_map(int **table)
{
	int ver_map;

	ver_map = ft_size_ver(table) * 3 + 10;
	if (ver_map > 720)
		ver_map = 720;
	if (ver_map < 150)
		ver_map = 150;
	return (ver_map);
}
*/

int		hor_loc(int **table, int line, int col, int value, int map_hor)
{
	int		hor;

	hor = 5 + 5 * col * ((map_hor - 10) / (ft_size_hor(table) + ft_size_ver(table)));
	return (hor);
}

int		ver_loc(int **table, int line, int value)
{
	int		ver;

	ver = ver_map(table) / 2 + value * 5 - line * 5;
	return (ver);
}

int		paint(int **table, char *content, char *name)
{
	t_draw	d;

	d.map_hor = hor_map(table);
	d.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, d.map_hor, ver_map(table), name);
	d.line = 0;
	while (table[d.line])
	{
		d.col = 0;
		while (table[d.line][d.col])
		{
			d.value = table[d.line][d.col];
			d.hor = hor_loc(table, d.line, d.col, d.value, d.map_hor);
			d.ver = ver_loc(table, d.line, d.value);
			d.color = ft_color(d.value);
			mlx_pixel_put(d.mlx_ptr, d.win_ptr, d.hor, d.ver, d.color);
			d.col++;
		}
		d.line++;
	}
	ft_link(table, content, d.line, d.col);
	mlx_key_hook(d.win_ptr, deal_key, (void *)0);
	mlx_loop(d.mlx_ptr);
	return (0);
}
