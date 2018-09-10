/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:59:41 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 20:41:53 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
int		fdf_index_hor(int **table)
{
	int index;
	int hor;
	int total_size;

	index = 20;
	hor = hor_map(table);
	if (hor == 2048)
	{
		total_size = ft_size_hor(table) + ft_size_ver(table);
		index = 1948 / total_size;
	}
	return (index);
}

int		fdf_index_ver(int **table)
{
	int max_int;
	int ver;
	int total_size;
	int index;

	index = 20;
	ver = ver_map(table);
	if (ver == 1152)
	{
		max_int = ft_max_int(table);
		total_size = ft_size_hor(table) + ft_size_ver(table) + max_int;
		index = 1052 / total_size;
	}
	return (index);
}
*/
int		fdf_index(int map_size, int size, int hor_ver)
{
	int index;

	index = 20;
	if (hor_ver == 1 && map_size == 2048)
		index = 1948 / size;
	if (hor_ver == 2 && map_size == 1152)
		index = 1052 / size;
	return (index);
}
