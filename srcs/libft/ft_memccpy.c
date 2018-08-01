/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:06:35 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/04 00:32:33 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst1;
	unsigned const char	*src1;
	int					i;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	i = 0;
	while (n--)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			return ((void *)dst + i + 1);
		i++;
	}
	return (NULL);
}
