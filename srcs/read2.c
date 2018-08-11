/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:24:30 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/11 17:50:37 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

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

int		**treatfile(int fd)
{
	t_table t;

	t.content = readfile(fd);
	t.cha_t = ft_split_keep_blanc(t.content, '\n');
	t.lin = 0;
	while (t.cha_t[t.lin])
		ft_strsplit(t.cha_t[t.lin++], ' ');
	printf("%s\n", t.cha_t[1][1]);

	return (0);
}
