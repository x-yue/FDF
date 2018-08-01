/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:23:03 by yuxu              #+#    #+#             */
/*   Updated: 2018/04/27 16:04:33 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this fonction returns the part of str before the char c (excluded)
*/

char	*ft_partstr(char *str, unsigned int i, char c)
{
	int				partcount;
	char			*part;
	unsigned int	strlen;
	int				partlen;
	char			*tmp;

	tmp = "";
	partcount = 0;
	strlen = ft_strlen(str);
	partlen = ft_partlen(str, i, c);
	if (str == NULL || i > strlen || partlen == 0)
	{
		part = ft_strdup(tmp);
		return (part);
	}
	if (!(part = (char*)malloc(sizeof(char) * partlen + 1)))
		return (NULL);
	if (str[i] == '\0' || str[i] == c)
		return ("");
	while (str[i] != c)
		part[partcount++] = str[i++];
	part[partcount] = 0;
	return (part);
}
