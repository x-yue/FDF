/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 04:53:03 by yuxu              #+#    #+#             */
/*   Updated: 2018/04/01 02:50:38 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_char(char const *sentence, char splitter)
{
	int i;
	int nb_words;

	if (sentence == NULL)
		return (0);
	i = 0;
	nb_words = 0;
	while (sentence[i])
	{
		if (sentence[i] == splitter)
			nb_words++;
		i++;
	}
	return (nb_words + 1);
}

static int		malloc_word(char **word, char const *sentence, char splitter,
					int counter)
{
	int start;
	int i;

	if (word == NULL || sentence == NULL)
		return (0);
	start = counter;
	while (sentence[counter] && sentence[counter] != splitter)
		counter++;
	if (sentence[counter] == splitter || sentence[counter] == '\0')
	{
		if (!(*word = (char*)malloc(sizeof(char) * (counter - start + 1))))
			return (-1);
	}
	i = 0;
	while (start + i <= counter)
	{
		(*word)[i] = sentence[start + i];
		i++;
	}
	(*word)[i - 1] = 0;
	counter++;
	return (counter);
}

/*
** cur_word is the current_word, str is the sentence
** i is the counter in other fonctions
** this is hidious, but i needed to save 4 lines..
*/

char			**ft_split_keep_blanc(char const *str, char splitter)
{
	char	**fresh;
	int		nb_word;
	int		cur_word;
	int		i;

	if (str == NULL)
		return (NULL);
	nb_word = ft_count_char(str, splitter);
	if ((!(fresh = (char**)malloc(sizeof(char*) * nb_word + 1))))
		return (NULL);
	i = 0;
	cur_word = 0;
	while (nb_word > 0 && str[i])
	{
		i = malloc_word(&fresh[cur_word], str, splitter, i);
		if (i == -1)
			return (NULL);
		nb_word--;
		cur_word++;
	}
	if (str[ft_strlen(str) - 1] == splitter)
		fresh[cur_word++] = "";
	fresh[cur_word] = NULL;
	return (fresh);
}
