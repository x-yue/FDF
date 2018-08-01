/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:02:57 by yuxu              #+#    #+#             */
/*   Updated: 2018/04/05 16:12:05 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **tab1, char **tab2)
{
	char	**res;
	int		a;
	int		b;

	if (tab1 == NULL || tab2 == NULL)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char) * (ft_tablen(tab1)
						+ ft_tablen(tab2)) + 1)))
		return (NULL);
	a = 0;
	b = 0;
	while (tab1[b])
		res[a++] = tab1[b++];
	b = 0;
	while (tab2[b])
		res[a++] = tab2[b++];
	res[a] = NULL;
	return (res);
}
