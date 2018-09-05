/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:24:25 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/05 16:23:04 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int		hor_map(int **table)
{
	int hor_map;
	int total_size;

	total_size = ft_size_hor(table) + ft_size_ver(table);
	hor_map = total_size * 20 + 100;
	if (hor_map < 150)
		hor_map = 150;
	if (hor_map > 2560)
		hor_map = 2048;
	return (hor_map);
}

int		ver_map(int **table)
{
	int ver_map;
	int total_size;

	total_size = ft_size_ver(table) + ft_size_hor(table) + ft_max_int(table);
	ver_map = total_size * 20 + 100;
	if (ver_map < 150)
		ver_map = 150;
	if (ver_map > 1440)
		ver_map = 1152;
	return (ver_map);
}
