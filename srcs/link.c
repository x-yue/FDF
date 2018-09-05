/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:27:58 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/06 01:06:59 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	left_to_right(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	if (d.col + 1 < ft_size_hor(table))
	{
		d.hor_right = hor_loc(table, d.line, d.col + 1, d.index_hor);
		d.ver_right = ver_loc(table, d.line, d.col + 1, d.index_ver);
		d.dist_hor = (d.hor_right - d.hor) / d.index_hor;
		if (d.ver_right > d.ver)
			d.dist_ver = (d.ver_right - d.ver) / (d.index_ver + d.value);
		if (d.ver_right < d.ver)
			d.dist_ver = (d.ver - d.ver_right) / (d.index_ver + d.value);
		d.x = d.hor;
		d.y = d.ver;
		while (d.x < d.hor_right)
		{
			d.x += d.dist_hor;
			if (d.ver_right > d.y)
				d.y += d.dist_ver;
			if (d.ver_right < d.y)
				d.y -= d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.y));
		}
	}
}

void	up_to_down(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	if (d.line + 1 < ft_size_ver(table))
	{
		d.hor_under = hor_loc(table, d.line + 1, d.col, d.index_hor);
		d.ver_under = ver_loc(table, d.line + 1, d.col, d.index_ver);
		d.dist_hor = (d.hor - d.hor_under) / d.index_hor;
		if (d.ver_under > d.ver)
			d.dist_ver = (d.ver_under - d.ver) / (d.index_ver + d.value);
		if (d.ver_under < d.ver)
			d.dist_ver = (d.ver - d.ver_under) / (d.index_ver + d.value);
		d.x = d.hor;
		d.y = d.ver;
		while (d.x > d.hor_under)
		{
			d.x -= d.dist_hor;
			if (d.ver_under > d.y)
				d.y += d.dist_ver;
			if (d.ver_under < d.y)
				d.y -= d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.y));
		}
	}
}

void	fdf_link(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	left_to_right(mlx_ptr, win_ptr, table, d);
	up_to_down(mlx_ptr, win_ptr, table, d);
	return ;
}
