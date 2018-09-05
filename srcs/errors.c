/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:18:38 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/05 14:26:36 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
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
*/
int		error_check(int fd, char *content, int **table)
{
	int		i;

	if (fd == -1 || content == NULL)
		return (-1);
	i = 0;
	while (content[i] != 0)
	{
		if ((content[i] <= '9' && content[i] >= '0') || content[i] == ' '
				|| content[i] == '\n' || content[i] == '-')
			i++;
		else
			return (-1);
	}
	return (0);
}
