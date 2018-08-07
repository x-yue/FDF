/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:18:04 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/07 21:30:57 by yuxu             ###   ########.fr       */
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

/*
void	one_line(int *line, char *content, int index)
{
	int		l;
	char	*word;

	l = 0;
	while (content[index] != '\n' && content[index]  != '\0')
	{
		printf("lin: %d index: %d\n", l, index);
		word = ft_partstr(content, index, ' ');
			printf("index (%d) word: (%s)  ", index, word);
		line[l] = ft_atoi(word);
			printf("number: (%d)\n", line[l]);
		index = index + ft_strlen(word) + 1;
		free(word);
		l++;
	}
//	line[l] = '\0';
}
*/
int		ft_freeatoi(char *word)
{
	int res;
	
	res = ft_atoi(word);
	if (word != NULL)
		free(word);
	return (res);
}

int		**treatfile(int fd)
{
	t_table t;

	t.content = readfile(fd);
	printf("print table\n%send of table\n", t.content);
	if (!(t.table = (int**)malloc(sizeof(int*) * ft_strlen(t.content) + 1)))
		return (NULL);
	t.col = 0;
	t.index = 0;
	while (t.content[t.index] != '\0')
	{
		t.lin = 0;
		t.lenth = (int)ft_partlen(t.content, t.index, '\n');
		if (!(t.table[t.col] = (int*)malloc(sizeof(int) * (t.lenth + 1))))
				return (NULL);
		while (t.content[t.index] != '\n' && t.content[t.index] != '\0')
		{
			t.word = ft_partstr(t.content, t.index, ' ');
			t.table[t.col][t.lin] = ft_freeatoi(t.word);
			t.index = t.index + ft_strlen(t.word) + 1;
			t.lin++;
		}
		t.table[t.col++][t.lin] = '\0';
		t.index++;
	}
	t.table[t.col] = NULL;
	return (t.table);
}
