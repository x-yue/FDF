/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:27:58 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/09 02:23:24 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	left_to_right(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	d.hor_next = hor_loc(table, d.line, d.col + 1, d.index_hor);
	d.ver_next = ver_loc(table, d.line, d.col + 1, d.index_ver);
	d.dist_hor = (d.hor_next - d.hor) / d.index_hor;
	if (d.ver_next > d.ver)
		d.dist_ver = (d.ver_next - d.ver) / d.index_ver;
	if (d.ver_next < d.ver)
		d.dist_ver = (d.ver - d.ver_next) / d.index_ver;
	d.x = d.hor;
	d.y = d.ver;
	if (d.ver_next > d.y)
	{
		while (d.x < d.hor_next || d.y < d.dist_ver)
		{
			d.x += d.dist_hor;
			d.y += d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.x, d.y));
		}
		return ;
	}
	if (d.dist_ver <= d.y)
	{
		while (d.x < d.hor_next || d.y > d.dist_ver)
		{
			d.x += d.dist_hor;
			d.y -= d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.x, d.y));
		}
		return ;
	}

	while (d.x < d.hor_next)
	{
		d.x += d.dist_hor;
		if (d.ver_next > d.y)
		{
			d.y += d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.y));
		}
		if (d.ver_next < d.y)
		{
			d.y -= d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.y));
		}
	}
}

void	up_to_down(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	d.hor_next = hor_loc(table, d.line + 1, d.col, d.index_hor);
	d.ver_next = ver_loc(table, d.line + 1, d.col, d.index_ver);
	d.dist_hor = (d.hor - d.hor_next) / d.index_hor;
	if (d.ver_next > d.ver)
		d.dist_ver = (d.ver_next - d.ver) / d.index_ver;
	if (d.ver_next < d.ver)
		d.dist_ver = (d.ver - d.ver_next) / d.index_ver;
	d.x = d.hor;
	d.y = d.ver;
	if (d.ver_next > d.y)
	{
		while (d.x > d.hor_next || d.y < d.hor_next)
		{
			d.x -= d.dist_hor;
			d.y += d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.x, d.y));
		}
		return ;
	}
	if (d.ver_next <= d.y)
	{
		while (d.x > d.hor_next || d.y > d.hor_next)
		{
			d.x -= d.dist_hor;
			d.y -= d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.x, d.y));
		}
		return ;
	}

	while (d.x > d.hor_next)
	{
		d.x -= d.dist_hor;
		if (d.ver_next > d.y)
		{
			d.y += d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.y));
		}
		if (d.ver_next < d.y)
		{
			d.y -= d.dist_ver;
			mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.y));
		}
	}
}
*/

void	left_to_right(void *mlx_ptr, void *win_ptr, t_draw d)
{
	d.dis_x = d.hor_right - d.hor;
	d.dis_y = d.ver_right - d.ver;
	d.median = 2 * d.dis_y - d.dis_x;
	d.median_inc1 = 2 * d.dis_y;
	d.median_inc2 = 2 * (d.dis_y - d.dis_x);
	d.x = d.hor;
	d.y = d.ver;
	while (d.x < d.hor_right)
	{
		if (d.median <= 0)
		{
			d.median += d.median_inc1;
			d.x++;
		}
		else
		{
			d.median += d.median_inc2;
			d.x++;
			d.y++;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.value));
	}
}

void	up_to_down(void *mlx_ptr, void *win_ptr, t_draw d)
{
	d.dis_x = d.hor_under - d.hor;
	d.dis_y = d.ver_under - d.ver;
	d.median = 2 * d.dis_x - d.dis_y;
	d.median_inc1 = 2 * d.dis_x;
	d.median_inc2 = 2 * (d.dis_x - d.dis_y);
	d.x = d.hor;
	d.y = d.ver;
	while (d.y < d.ver_under)
	{
		if (d.median >= 0)
		{
			d.median += d.median_inc1;
			d.x--;
		}
		else
		{
			d.median += d.median_inc2;
			d.x--;
			d.y++;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, d.x, d.y, color(d.value));
	}
}

void	fdf_link(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	if (d.col + 2 < d.col_max && d.line + 1 < d.line_max)
	{
		d.hor_right = hor_loc(table, d.line, d.col + 1, d.index_hor);
		d.ver_right = ver_loc(table, d.line, d.col + 1, d.index_ver);
		left_to_right(mlx_ptr, win_ptr, d);
	}
//		left_to_right(mlx_ptr, win_ptr, table, d)
	if (d.line + 2 < d.line_max && d.col + 1 < d.col_max)
	{
		d.hor_under = hor_loc(table, d.line + 1, d.col, d.index_hor);
		d.ver_under = ver_loc(table, d.line + 1, d.col, d.index_ver);
		up_to_down(mlx_ptr, win_ptr, d);
	}
//		up_to_down(mlx_ptr, win_ptr, table, d);
	return ;
}
