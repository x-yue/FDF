/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 00:24:00 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/02 06:12:32 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;
	int			i;

	dst1 = (char*)dst;
	src1 = (const char*)src;
	if (dst > src)
	{
		i = len;
		while (i--)
			dst1[i] = src1[i];
		return (dst1);
	}
	i = 0;
	while (len--)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
