/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:24:30 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 15:58:40 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		*dimension_remove(char *str, int lenth)
{
	int		*array;
	char	**char_t;
	int		word_nbr;

	word_nbr = 0;
	char_t = ft_strsplit(str, ' ');
	if (!(array = (int*)malloc(sizeof(int) * lenth + 1)))
		return (NULL);
	while (char_t[word_nbr])
	{
		array[word_nbr] = (ft_atoi(char_t[word_nbr]) * 10 + 1);
		word_nbr++;
	}
	array[word_nbr] = 0;
	return (array);
}

int		**treatfile(char *content)
{
	t_table t;

	t.lenth = (int)ft_strlen(content);
	t.char_t = ft_strsplit(content, '\n');
	if (!(t.table = (int**)malloc(sizeof(int*) * t.lenth + 1)))
		return (NULL);
	t.lin = 0;
	while (t.char_t[t.lin])
	{
		t.table[t.lin] = dimension_remove(t.char_t[t.lin], t.lenth);
		t.lin++;
	}
	t.table[t.lin] = NULL;
	return (t.table);
}
