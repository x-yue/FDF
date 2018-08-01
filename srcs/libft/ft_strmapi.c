/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 23:09:48 by yuxu              #+#    #+#             */
/*   Updated: 2018/03/19 17:58:20 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	char	*result;

	i = 0;
	str = (char*)s;
	if (s == NULL || str == NULL)
		return (NULL);
	if (!(result = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		result[i] = (*f)(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
