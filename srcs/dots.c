/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:54:43 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/05 22:15:01 by yuxu             ###   ########.fr       */
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
*/

int		hor_loc(int **table, int line, int col, int index)
{
	int		hor;

	hor = 50 + ft_size_ver(table) * index + (col - line) * index;
	return (hor);
}

int		ver_loc(int **table, int line, int col, int index)
{
	int		ver;
	int		value;

	value = (table[line][col] - 1) / 10;
	ver = 50 + ft_max_int(table) * index + (line + col - value) * index;
	return (ver);
}

int		paint(void *mlx_ptr, void *win_ptr, int **table, char *content)
{
	t_draw	d;

	d.index_hor = fdf_index_hor(table);
	d.index_ver = fdf_index_ver(table);
	d.line = 0;
	while (table[d.line])
	{
		d.col = 0;
		while (table[d.line][d.col])
		{
			d.value = ((table[d.line][d.col]) - 1) / 10;
			d.hor = hor_loc(table, d.line, d.col, d.index_hor);
			d.ver = ver_loc(table, d.line, d.col, d.index_ver);
			mlx_pixel_put(mlx_ptr, win_ptr, d.hor, d.ver, color(d.ver));
			fdf_link(mlx_ptr, win_ptr, table, d);
			d.col++;
		}
		d.line++;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
