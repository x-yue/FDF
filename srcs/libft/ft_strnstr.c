/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:13:59 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/04 22:56:06 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int n;
	int l;

	n = 0;
	if (haystack[0] && needle[0])
		l = 0;
	if ((int)len >= (l = ft_strlen(needle)))
	{
		if (l == 0)
			return ((char*)haystack);
		while (haystack[n] && n <= (int)len - l)
		{
			i = 0;
			while (haystack[n + i] && needle[i] == haystack[n + i])
			{
				if (needle[i + 1] == '\0')
					return ((char*)haystack + n);
				i++;
			}
			n++;
		}
	}
	return (0);
}
