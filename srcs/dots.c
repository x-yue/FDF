/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:54:43 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/06 01:07:21 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	paint(void *mlx_ptr, void *win_ptr, int **table, char *content)
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
}
