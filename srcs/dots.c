/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:54:43 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 21:34:14 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_index(int map_size, int size, int hor_ver)
{
	int		index;

	index = 20;
	if (hor_ver == 1 && map_size == 2048)
		index = 1948 / size;
	if (hor_ver == 2 && map_size == 1152)
		index = 1052 / size;
	return (index);
}

int		hor_loc(t_fdf f, int line, int col, t_draw d)
{
	int		hor;

	hor = 50 + (ft_size_ver(f.table) + col - line ) * d.index_hor;
	return (hor);
}

int		ver_loc(t_fdf f, int line, int col, t_draw d)
{
	int		ver;
	int		value;

	value = (f.table[line][col] - 1) / 10;
	ver = 50 + (d.max_int + line + col - value) * d.index_ver;
	return (ver);
}

void	paint(t_fdf f)
{
	t_draw	d;

	d.index_hor = fdf_index(f.map_size_hor, f.size_hor, 1);
	d.index_ver = fdf_index(f.map_size_ver, f.size_ver, 2);
	d.max_int = ft_max_int(f.table);
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
			d.hor = hor_loc(f, d.line, d.col, d);
			d.ver = ver_loc(f, d.line, d.col, d);
			mlx_pixel_put(f.mlx_ptr, f.win_ptr, d.hor, d.ver, color(d.value));
			fdf_link(f.mlx_ptr, f.win_ptr, f, d);
			d.col++;
		}
		d.line++;
	}
}
