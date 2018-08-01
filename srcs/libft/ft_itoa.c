/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 03:17:11 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/04 22:41:20 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*nbrrr(int nb, int len)
{
	char	*str;
	int		tmp;

	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	tmp = nb;
	if (nb < 0)
		nb = nb * -1;
	while (len >= 1)
	{
		len--;
		str[len] = nb % 10 + 48;
		nb /= 10;
	}
	if (tmp < 0)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	int		m;
	char	*str;
	int		i;
	int		tmp;

	i = 1;
	m = 1;
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		m++;
	while (n /= 10)
		m++;
	str = nbrrr(tmp, m);
	return (str);
}
