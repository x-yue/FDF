/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:37:09 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/21 11:38:38 by yuxu             ###   ########.fr       */
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
	int		i;
	int		n;

	content = readfile(fd);
	table = treatfile(content);
	if (error_check(fd, content, table) == -1)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		return ;
	}
	paint(table, content, name);
//	i = 0;
//	while (table[i])
///	{
//		n = 0;
//		while (table[i][n] != 0)
//		{
//			ft_putnbr(table[i][n]);
//			ft_putchar(' ');
//			n++;
//		}
//		ft_putstr("\n");
//		i++;
//	}
	return ;
}

int		main(int ac, char **av)
{
	int		fd;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	fdf(fd, av[1]);
	close(fd);
	return (0);
}
