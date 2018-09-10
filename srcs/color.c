/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:08:53 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 15:58:18 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		color(int value)
{
	int color;

	if (value == 0)
		color = 0xFF66CC;
	if (value < 0 && value > -10)
		color = 0xD61E74;
	if (value <= -10)
		color = 0xFF0F13;
	if (value > 0 && value < 10)
		color = 0x9D1FE0;
	if (value >= 10)
		color = 0x2BBCFF;
	return (color);
}
