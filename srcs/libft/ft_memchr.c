/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 00:12:05 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/02 00:22:52 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	int					i;

	s1 = s;
	i = 0;
	while (n--)
	{
		if (s1[i] == (unsigned char)c)
			return ((unsigned char*)s1 + i);
		i++;
	}
	return (NULL);
}
