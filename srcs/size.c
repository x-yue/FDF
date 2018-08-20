/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:24:25 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/20 16:41:40 by yuxu             ###   ########.fr       */
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
	hor += ft_max_int(table);
	return (hor);
}
