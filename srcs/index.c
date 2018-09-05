/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:59:41 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/05 15:12:39 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_index_hor(int **table)
{
	int index;
	int hor;
	int total_size;

	hor = hor_map(table);
	total_size = ft_size_hor(table) + ft_size_ver(table);
	index = 20;
	if (hor == 2048)
		index = (hor - 100) / total_size;
	return (index);
}

int		fdf_index_ver(int **table)
{
	int max_int;
	int ver;
	int total_size;
	int index;

	max_int = ft_max_int(table);
	ver = ver_map(table);
	total_size = ft_size_hor(table) + ft_size_ver(table) + max_int;
	index = 20;
	if (ver == 1152)
		index = (ver - 100) / total_size;
	return (index);
}
