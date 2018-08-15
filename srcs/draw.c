/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:54:43 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/15 19:04:24 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	ft_putstr("<3");
	//	mlx_pixel_put(mlx_ptr, win_ptr, 
	return (0);
}

int		ft_dot(int **table, int lin, int col)
{
	t_draw d;
	
	d.vkeeper = table[lin][col];
	mlx_pixel_put(d.mlx_ptr, d.win_ptr, lin * 10, col * 10, 0xFFFFFF);
	return (0);
}

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

int		ft_map(void)
{
	t_draw	d;

	d.map_hor = 1618;
	d.map_ver = 1000;
	d.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, d.map_hor, d.map_ver, "New Window");
	mlx_key_hook(d.win_ptr, deal_key, (void *)0);
	mlx_loop(d.mlx_ptr);
	return (0);
}

int		paint(int	**table, char *name)
{
	t_draw	d;
	//ft_map();
	d.map_hor = 1618;
	d.map_ver = 1000;
	d.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, d.map_hor, d.map_ver, name);
	d.line = 0;
	while (table[d.line])
	{
		d.col = 0;
		while (table[d.line][d.col])
		{
			ft_dot(table, d.line, d.col);
			d.col++;
		}
		d.line++;
	}
	mlx_key_hook(d.win_ptr, deal_key, (void *)0);
	mlx_loop(d.mlx_ptr);
	return (0);
}
