/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:08:53 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/05 22:08:21 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(int ver)
{
	int color;

	color = 0xFF66AA;
	color += ver * 16;
/*
				 
	if (value == 0)
		color = 0xFFFFFF;
	if (value > 0 && value <= 5)
		color = 0xFFCCEE;
	if (value > 5)
		color = 0xFF66CC;
	if (value < 0 && value >= -5)
		color = 0xEECCFF;
	if (value < -5)
		color = 0x66FFCC;
*/	
	return (color);
}
