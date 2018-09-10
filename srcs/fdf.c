/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:37:09 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 21:25:46 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*readfile(int fd)
{
	int		rd;
	char	buf[BUFF_SIZE + 1];
	char	*content;

	content = NULL;
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
		content = joinfree(content, buf, rd);
	if (rd == -1)
		return (NULL);
	return (content);
}

int		check_table(int **table)
{
	int line;
	int bm;
	int col;

	col = 0;
	while (table[0][col])
		col++;
	bm = col;
	line = 1;
	while (table[line])
	{
		col = 0;
		while (table[line][col])
			col++;
		if (col != bm)
			return (-1);
		line++;
	}
	return (0);
}

void	fdf(int fd, char *name)
{
	t_fdf	f;

	if ((f.content = readfile(fd)) == NULL)
	{
		ft_putstr_fd("No data found.\n", 2);
		return ;
	}
	f.table = treatfile(f.content);
	if (check_table(f.table) == -1)
	{
		ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
		return ;
	}
	f.mlx_ptr = mlx_init();
	f.size_hor = ft_size_hor(f.table) + ft_size_ver(f.table);
	f.size_ver = f.size_hor + ft_max_int(f.table);
	f.map_size_hor = map_size(f.size_hor, 1);
	f.map_size_ver = map_size(f.size_ver, 2);
	f.win_ptr = mlx_new_window(f.mlx_ptr, f.map_size_hor, f.map_size_ver, name);
	paint(f);
	mlx_key_hook(f.win_ptr, deal_key, (void *)100);
	mlx_loop(f.mlx_ptr);
	return ;
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			ft_putstr_fd("No file ", 2);
			ft_putstr_fd(av[1], 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
		fdf(fd, av[1]);
		close(fd);
	}
	if (ac != 2)
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n", 2);
	return (0);
}
