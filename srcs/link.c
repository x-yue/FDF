/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:27:58 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/05 22:42:09 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	make_a_point(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.value));
	return ;
}*/

void	left_to_right(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	int		map_hor;

	map_hor = ft_size_hor(table);
	if (table[d.line][d.col + 1] && d.col + 1 <= map_hor)
	{
		d.hor_next = hor_loc(table, d.line, d.col + 1, d.index_hor);
		d.ver_next = ver_loc(table, d.line, d.col + 1, d.index_ver);
//		d.dist_hor = (d.hor_next - d.hor) / d.index_hor;
//		if (d.ver_next > d.ver)
//			d.dist_ver = (d.ver_next - d.ver) / (d.index_ver + d.value);
//		if (d.ver_next < d.ver)
//			d.dist_ver = (d.ver - d.ver_next) / (d.index_ver + d.value);
		d.x = d.hor;
		d.y = d.ver;
		while (d.x < d.hor_next || d.y != d.ver_next)
		{
//			d.x += d.dist_hor;
			d.x++;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.value));
//			make_a_point(mlx_ptr, win_ptr, table, d);
			if (d.ver_next > d.y)
				d.y++;
//				d.y += d.dist_ver;
			if (d.ver_next < d.y)
				d.y--;
//				d.y -= d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.value));
//			make_a_point(mlx_ptr, win_ptr, table, d);
		}
	}
	return ;
}

void	up_to_down(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	int		map_ver;

	map_ver = ft_size_ver(table);
	if (table[d.line + 1][d.col] && d.line + 1 <= map_ver)
	{
		d.hor_next = hor_loc(table, d.line + 1, d.col, d.index_hor);
		d.ver_next = ver_loc(table, d.line + 1, d.col, d.index_ver);
//		d.dist_hor = (d.hor - d.hor_next) / d.index_hor;
//		if (d.ver_next > d.ver)
//			d.dist_ver = (d.ver_next - d.ver) / (d.index_ver + d.value);
//		if (d.ver_next < d.ver)
//			d.dist_ver = (d.ver - d.ver_next) / (d.index_ver + d.value);
		d.x = d.hor;
		d.y = d.ver;
		while (d.x > d.hor_next || d.y != d.ver_next)
		{
			d.x--;
//			d.x -= d.dist_hor;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.value));
//			make_a_point(mlx_ptr, win_ptr, table, d);
			if (d.ver_next > d.y)
				d.y++;
//				d.y += d.dist_ver;
			if (d.ver_next < d.y)
				d.y--;
				//d.y -= d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.value));
//			make_a_point(mlx_ptr, win_ptr, table, d);
		}
	}
	return ;
}

void	fdf_link(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	left_to_right(mlx_ptr, win_ptr, table, d);
	up_to_down(mlx_ptr, win_ptr, table, d);
	return;
}
