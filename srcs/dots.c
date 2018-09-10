/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:54:43 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 19:48:47 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	paint(t_fdf f)
{
	t_draw	d;

	d.index_hor = fdf_index_hor(f.table);
	d.index_ver = fdf_index_ver(f.table);
	d.line_max = ft_size_ver(f.table);
	d.col_max = ft_size_hor(f.table);
	d.line = 0;
	while (f.table[d.line])
	{
		d.col = 0;
		while (f.table[d.line][d.col] &&
				(d.col + 1 < d.col_max && d.line + 1 < d.line_max))
		{
			d.value = (f.table[d.line][d.col] - 1) / 10;
			d.hor = hor_loc(f.table, d.line, d.col, d.index_hor);
			d.ver = ver_loc(f.table, d.line, d.col, d.index_ver);
			mlx_pixel_put(f.mlx_ptr, f.win_ptr, d.hor, d.ver, color(d.value));
			fdf_link(f.mlx_ptr, f.win_ptr, f.table, d);
			d.col++;
		}
		d.line++;
	}
}
