/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 00:05:20 by yuxu              #+#    #+#             */
/*   Updated: 2018/04/24 21:20:10 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		n;
	int		f;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(fresh = (char*)malloc(sizeof(char) * (ft_strlen(s1) +
				ft_strlen(s2)) + 1)))
		return (NULL);
	n = 0;
	f = 0;
	while (s1[n])
		fresh[f++] = s1[n++];
	n = 0;
	while (s2[n])
		fresh[f++] = s2[n++];
	fresh[f] = '\0';
	return (fresh);
}
