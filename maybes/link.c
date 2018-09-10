/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:27:58 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 13:38:48 by yuxu             ###   ########.fr       */
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
/*
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
			d.x++;
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
*/

int		ft_abs(int number)
{
	if (number > 0)
		return (number);
	if (number < 0)
		return (number * -1);
	return (0);
}

void	fdf_line(void *mlx_ptr, int *win_ptr, t_line l)
{
	l.dis_x = ft_abs(l.x1 - l.x0);
	l.inc_x = l.x0 < l.x1 ? 1 : -1;
	l.dis_y = ft_abs(l.y1 - l.y0);
	l.inc_y = l.y0 < l.y1 ? 1 : -1;
	l.err = (l.dis_x > l.dis_y ? l.dis_x : - l.dis_y) / 2;
	while (l.x0 != l.x1 || l.y0 != l.y1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, l.x0, l.y0, color(l.y0));
		l.e = l.err;
		if (l.e > -l.dis_x)
		{
			l.err -= l.dis_y;
			l.x0 += l.inc_x;
		}
		if (l.e < l.dis_y)
		{
			l.err += l.dis_x;
			l.y0 += l.inc_y;
		}
	}
}

void	fdf_link(void *mlx_ptr, void *win_ptr, int **table, t_draw d)
{
	t_line l;

	l.x0 = d.hor;
	l.y0 = d.ver;
	if (d.col + 1 < d.col_max && d.line + 1 < d.line_max)
	{
		l.x1 = hor_loc(table, d.line, d.col + 1, d.index_hor);
		l.y1 = ver_loc(table, d.line, d.col + 1, d.index_ver);
		fdf_line(mlx_ptr, win_ptr, l);
		l.x1 = hor_loc(table, d.line + 1, d.col, d.index_hor);
		l.y1 = ver_loc(table, d.line + 1, d.col, d.index_ver);
		fdf_line(mlx_ptr, win_ptr, l);
	}
	return ;
}
