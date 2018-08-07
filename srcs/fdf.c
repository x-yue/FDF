/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:37:09 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/07 21:31:19 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

void	fdf(int fd)
{
	int		**table;
	int		i;
	int		n;

//	if (error_check(fd) == -1)
//		return ;
	table = treatfile(fd);
//	paint();
	i = 0;
	while (table[i])
	{
		n = 0;
		printf("%d ", i);
		while (table[i][n])
		{
			printf("%d ", table[i][n]);
			n++;
		}
		printf("\n");
		i++;
	}
	return ;
}

int		main(int ac, char **av)
{
	int fd;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	fdf(fd);
	close(fd);
	return (0);
}
