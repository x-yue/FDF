/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:01:14 by yuxu              #+#    #+#             */
/*   Updated: 2018/04/26 00:32:56 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function returns the str removing a part at the beginning of it
** including the char at the str[len] position
*/

char	*ft_strmove(char *str, size_t len)
{
	char	*res;
	int		i;
	size_t	strlen;

	if (str == NULL)
		return (NULL);
	strlen = ft_strlen(str);
	if (len > strlen)
		len = strlen;
	if (!(res = (char*)malloc(sizeof(char) * (strlen - len) + 1))
			|| !str || len > strlen)
		return (NULL);
	i = 0;
	while (str[len])
		res[i++] = str[len++];
	free(str);
	res[i] = 0;
	return (res);
}
