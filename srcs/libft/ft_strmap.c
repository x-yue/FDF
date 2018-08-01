/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:45:13 by yuxu              #+#    #+#             */
/*   Updated: 2018/03/19 17:51:05 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*result;
	int		i;

	str = (char*)s;
	if (s == NULL || str == NULL)
		return (NULL);
	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		result[i] = (*f)(str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
