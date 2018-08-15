/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:18:38 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/15 17:13:20 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_check(int fd, char *content)
{
	int		i;

	if (fd == -1 || content == NULL)
		return (-1);
	i = 0;
	while (content[i] != 0)
	{
		if ((content[i] <= '9' && content[i] >= '0') || content[i] == ' '
				|| content[i] == '\n' || content[i] == '-')
			i++;
		else
			return (-1);
	}
	return (0);
}
