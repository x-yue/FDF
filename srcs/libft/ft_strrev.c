/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:21:24 by exam              #+#    #+#             */
/*   Updated: 2018/03/22 05:02:38 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		n;
	int		i;
	char	tmp;

	if (str == NULL)
		return (NULL);
	n = 0;
	i = ft_strlen(str) - 1;
	while (str[n] && n < i)
	{
		tmp = str[n];
		str[n] = str[i];
		str[i] = tmp;
		n++;
		i--;
	}
	return (str);
}
