/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:37:52 by yuxu              #+#    #+#             */
/*   Updated: 2018/04/26 00:36:05 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_partlen(const char *s, unsigned int i, char c)
{
	unsigned int start;
	unsigned int strlen;

	start = i;
	strlen = ft_strlen(s);
	if (s == NULL || i > strlen || ft_index((char*)s, c) == -1)
		return (0);
	while (s[start] != c)
		start++;
	if (s[start + 1] == '\0' && s[start] != c && c != '\0')
		return (0);
	return (start - i);
}
