/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:04:12 by exam              #+#    #+#             */
/*   Updated: 2018/03/22 21:02:13 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	compare(unsigned int first, unsigned int second)
{
	if (first >= second)
		return (second);
	return (first);
}

unsigned int	ft_pgcd(unsigned int first, unsigned int second)
{
	unsigned int i;

	if (first <= 0 || second <= 0)
		return (0);
	i = compare(first, second);
	while (i > 1)
	{
		if (first % i == 0 && second % i == 0)
			return (i);
		i--;
	}
	return (i);
}
