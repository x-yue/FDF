/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:47:48 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/03 22:15:10 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t n;
	size_t dest_end_index;

	if (dest_size == 0)
		return (ft_strlen(src));
	dest_end_index = ft_strlen(dest);
	if (dest_size < dest_end_index)
		return (ft_strlen(src) + dest_size);
	n = 0;
	while (src[n] && dest_end_index < dest_size - 1)
	{
		dest[dest_end_index] = src[n];
		dest_end_index++;
		n++;
	}
	dest[dest_end_index] = '\0';
	return (ft_strlen(dest) + ft_strlen(src) - n);
}
