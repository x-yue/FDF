/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 00:01:50 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/02 00:11:43 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s11;
	const unsigned char	*s22;
	int					i;

	s11 = s1;
	s22 = s2;
	i = 0;
	while (n--)
	{
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
		if (s11[i] == s22[i])
			i++;
	}
	return (0);
}
