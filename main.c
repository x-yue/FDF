/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:54:43 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/01 20:26:36 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int		deal_key(int key, void *param)
{
	ft_putchar('<');
	ft_putchar('3');
	
//	mlx_pixel_put(mlx_ptr, win_ptr, 
	return (0);
}
/*
int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		hor;
	int		ver;
	int		index;
	int		inc;
	int		map_hor;
	int		map_ver;
	int		ini;

	inc = 10;
	index = 100;
	ini = 100;
	map_hor = 809;
	map_ver = 500;
	mlx_ptr = mlx_init();// open a screen 
	win_ptr = mlx_new_window(mlx_ptr, map_hor, map_ver, "test window"); //identify the window
	ver = ini;
	while (ver <= map_ver - index + inc / 2)
	{
		hor = ini;
		mlx_pixel_put(mlx_ptr, win_ptr, hor, ver, 0xFFFFFF); //
		while (hor <= map_hor - index + inc / 2)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, hor, ver, 0xFFFFFF); //
			hor = hor + inc;
		}
		ver = ver + inc;
		ini++;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr); //where to draw and gestion des evenements
	return (0);
}
*/
int		main(int ac, char **av)
{
	int fd;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	close (fd);
	return (0);
}
