/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 04:53:03 by yuxu              #+#    #+#             */
/*   Updated: 2018/03/19 18:04:55 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *sentence, char splitter)
{
	int i;
	int nb_words;

	i = 0;
	nb_words = 0;
	if (sentence == NULL)
		return (0);
	while (sentence[i])
	{
		while (sentence[i] == splitter && sentence[i])
			i++;
		if (sentence[i] == '\0')
			return (nb_words);
		nb_words++;
		while (sentence[i] != splitter && sentence[i])
			i++;
	}
	return (nb_words);
}

static int		malloc_word(char **word, char const *sentence, char splitter,
					int counter)
{
	int word_starts_index;
	int i;

	word_starts_index = counter;
	if (word == NULL || sentence == NULL)
		return (0);
	while (sentence[counter] != splitter && sentence[counter])
		counter++;
	if (!(*word =
			(char*)malloc(sizeof(char) * (counter - word_starts_index + 1))))
		return (-1);
	i = 0;
	while (word_starts_index + i <= counter)
	{
		(*word)[i] = sentence[word_starts_index + i];
		i++;
	}
	(*word)[i - 1] = 0;
	return (counter);
}

char			**ft_strsplit(char const *sentence, char splitter)
{
	char	**fresh;
	int		nb_words;
	int		current_word;
	int		counter;

	nb_words = word_count(sentence, splitter);
	if ((!(fresh = (char**)malloc(sizeof(char*) * nb_words + 1))) ||
			sentence == NULL)
		return (NULL);
	counter = 0;
	current_word = 0;
	while (nb_words > 0)
	{
		while (sentence[counter] == splitter)
			counter++;
		counter = malloc_word(&fresh[current_word], sentence, splitter,
								counter);
		if (counter == -1)
			return (NULL);
		nb_words--;
		current_word++;
	}
	fresh[current_word] = 0;
	return (fresh);
}
