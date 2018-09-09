/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:37:09 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/08 19:35:50 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*readfile(int fd)
{
	int		rd;
	char	buf[BUFF_SIZE + 1];
	char	*content;

	content = NULL;
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
		content = joinfree(content, buf, rd);
	return (content);
}

void	fdf(int fd, char *name)
{
	char	*content;
	int		**table;
	void	*mlx_ptr;
	void	*win_ptr;

	content = readfile(fd);
	table = treatfile(content);
	if (error_check(content, table) == -1)
		return ;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, hor_map(table), ver_map(table), name);
	paint(mlx_ptr, win_ptr, table, content);
	mlx_key_hook(win_ptr, deal_key, (void *)100);
	mlx_loop(mlx_ptr);
	return ;
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			error_message(av[1]);
			return (0);
		}
		fdf(fd, av[1]);
		close(fd);
	}
	if (ac != 2)
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	return (0);
}
