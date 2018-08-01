/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 04:58:08 by yuxu              #+#    #+#             */
/*   Updated: 2018/04/01 03:04:55 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	if (tab == 0 || size == 0)
		return ;
	i = 0;
	while (tab[i])
		i++;
	if (size > i)
		size = i;
	i = 0;
	j = 1;
	while (i < size - 1 && j < size && tab[j] && tab[i])
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
		j = i + 1;
	}
}
