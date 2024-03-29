/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:24:25 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 20:50:06 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_max_int(int **table)
{
	int max;
	int line;
	int col;
	int number;

	line = 0;
	max = 0;
	while (table[line])
	{
		col = 0;
		while (table[line][col])
		{
			number = table[line][col];
			if (number < 0)
				number = number * -1;
			if (number > max)
				max = number;
			col++;
		}
		line++;
	}
	max = (max - 1) / 10;
	return (max);
}

int		ft_size_ver(int **table)
{
	int ver;

	ver = 0;
	while (table[ver])
		ver++;
	return (ver);
}

int		ft_size_hor(int **table)
{
	int hor;
	int line;
	int col;
	int count;

	hor = 0;
	count = 0;
	line = 0;
	while (table[line])
	{
		col = 0;
		count = 0;
		while (table[line][col])
		{
			count++;
			col++;
		}
		if (count > hor)
			hor = count;
		line++;
	}
	return (hor);
}

int		map_size(int size, int hor_ver)
{
	int map_size;

	map_size = size * 20 + 100;
	if (map_size < 150)
		return (map_size = 150);
	if (map_size > 2560 && hor_ver == 1)
		return (map_size = 2048);
	if (map_size > 1440 && hor_ver == 2)
		return (map_size = 1152);
	return (map_size);
}
