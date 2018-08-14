/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:10:17 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/11 17:50:44 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

//# include "mlx.h"
# include "../minilibx_macos/mlx.h"
# include "../srcs/libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 100

typedef	struct		s_table
{
	char			*content;
	int				**table;
	char			**cha_t;
	int				lin;
	
	int				lenth;
	int				index;
	int				col;
	char			*word;
	int				w_len;
}					t_table;

void				fdf(int fd);
int					paint(void);
int					deal_key(int key, void *param);
int					**treatfile(int fd);
char				*readfile(int fd);

#endif
