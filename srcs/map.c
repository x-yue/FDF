/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:24:25 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/23 17:22:23 by yuxu             ###   ########.fr       */
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

	hor_map = ft_size_hor(table) * 20 + 100;
	if (hor_map > 1280)
		hor_map = 1280;
	if (hor_map < 150)
		hor_map = 150;
	return (hor_map);
}

int		ver_map(int **table)
{
	int ver_map;

	ver_map = ft_size_ver(table) * 20 + ft_max_int(table) * 10+ 100;
	if (ver_map > 720)
		ver_map = 720;
	if (ver_map < 150)
		ver_map = 150;
	return (ver_map);
}
