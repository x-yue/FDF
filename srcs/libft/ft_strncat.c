/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:21:47 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/02 20:41:36 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (dest[i])
		i++;
	while (src[m] && m < (int)n)
	{
		dest[i] = src[m];
		i++;
		m++;
	}
	dest[i] = '\0';
	return (dest);
}
