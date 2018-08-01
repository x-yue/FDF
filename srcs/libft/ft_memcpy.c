/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:14:31 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/03 19:01:27 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*src2;
	char	*dst2;

	i = 0;
	src2 = (char*)src;
	dst2 = (char*)dst;
	while (n != 0)
	{
		dst2[i] = src2[i];
		i++;
		n--;
	}
	return (dst);
}
