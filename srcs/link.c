/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:27:58 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 19:39:01 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	l.err = (l.dis_x > l.dis_y ? l.dis_x : -l.dis_y) / 2;
	while (l.x0 != l.x1 || l.y0 != l.y1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, l.x0, l.y0, color(l.value));
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
	l.value = d.value;
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
