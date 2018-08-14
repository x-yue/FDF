/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:18:04 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/11 17:50:42 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

int		return_count(char *content, char c)
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == c)
			counter++;
		i++;
	}
	printf("there are %d returns in content\n", counter);
	return (counter);
}

char	*comply_str(char *str)
{
	char	*res;
	int		count;
	int		i;
	int		r;

	count = return_count(str, '\n');
	if (count > 0)
	{
		if (!(res = (char*)malloc(sizeof(char) * ft_strlen(str) + count + 1)))
			return (NULL);
		i = 0;
		r = 0;
		while (str[i] != 0)
		{
			if (i == 0 && str[i] == '\n')
				i++;
			//	printf("%c == %c\n", res[r], str[i]);
			if (str[i + 1] == '\n' && str[i] != ' ')
			{
				printf("%c == %c\n", res[r], str[i]);
				res[r] = ' ';
				r++;
			}
			res[r] = str[i];
			i++;
			r++;
		}
	//	printf("content:\n%s\nres:\n%s\nwhere we are at: (%c) and (%c)\n", str, res, str[i], res[r]);
		res[r] = '\0';
		printf("content:\n%s\nres:\n%s\nwhere we are at: (%c) and (%c)\n", str, res, str[i], res[r]);
		return (res);
	}
	return (str);
}

char	*readfile_compliance(int fd)
{
	int		rd;
	char	buf[BUFF_SIZE + 1];
	char	*content;

	content = NULL;
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
		content = joinfree(content, buf, rd);
	comply_str(content);
	return (content);
}

int		ft_atoi_large_free(char *word)
{
	int		res;

	res = (ft_atoi(word) * 10 + 1);
	if (word != NULL)
		free(word);
	return (res);
}

int		**treatfile(int fd)
{
	t_table t;

	t.content = readfile_compliance(fd);
//	printf("print table\n%send of table\n", t.content);
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
			t.table[t.col][t.lin] = ft_atoi_large_free(t.word);
			t.index = t.index + 1 + ft_strlen(t.word);
			t.lin++;
		}
		t.table[t.col++][t.lin] = '\0';
		t.index++;
	}
	t.table[t.col] = NULL;
	return (t.table);
}

/*
int		**convert_char_int(char *content, char **char_table)
{
	int		**int_table;
	int		line;
	int		col;

	if (!(int_table = (int**)malloc(sizeof(int*) * ft_strlen(content) + 1)))
		return (NULL);
	line = 0;
	while (char_table[line])
	{
		if (!(int_table = (int*)malloc(sizeof(int) * ft_strlen(content) + 1)))
			return (NULL);
		col = 0;
		while (char_table[line][col])
		{
			int_table[line][col] = ft_atoi_large_free(char_table[line][col]);
			col++;
		}
		int_table[line][col] = 0;
		line++;
	}
	int_table[line] = NULL;
	return (int_table);
}

int		**treatfile(int fd)
{
	t_table t;

	t.content = readfile(fd);
//	if (!(t.table = (int**)malloc(sizeof(int*) * ft_strlen(t.content) + 1)))
//		return (NULL);
	if (!(t.cha_t = (char**)malloc(sizeof(char*) * ft_strlen(t.content) + 1)))
		return (NULL);
	t.cha_t = ft_strsplit(t.content, '\n');
	t.lin = 0;
	while (t.cha_t[t.lin] != NULL)
	{
		ft_strsplit(t.cha_t[t.lin], ' ');
		t.lin++;
	}
//	if (!(t.cha_t[t.lin] = (char*)malloc(sizeof(char) *
//					ft_partlen(t.content, '\n') + 1)))
//		return (NULL);
	t.table = convert_char_int(t.content, t.cha_t);
	return (t.table);
}*/
