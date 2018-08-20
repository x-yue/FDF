/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:10:17 by yuxu              #+#    #+#             */
/*   Updated: 2018/08/20 15:37:07 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

//# include "mlx.h"
# include "../minilibx_macos/mlx.h"
# include "../srcs/libft/libft.h"
# include <fcntl.h>
# include <OpenGL/gl3.h>

# define BUFF_SIZE 100

typedef	struct		s_table
{
	char			*content;
	int				**table;
	char			**char_t;
	int				lin;
	int				col;
	int				lenth;
}					t_table;

typedef	struct		s_draw
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				line;
	int				col;
	int				map_hor;
	int				map_ver;
	int				value;
	int				color;
	int				hor;
	int				ver;
}					t_draw;

int					paint(int **table, char *content, char *name);
int					deal_key(int key, void *param);
int					ft_color(int value);
int					**treatfile(char *content);
int					error_check(int fd, char *content);
void				ft_link(int **table, char *content, int line, int col);
int					ft_size_hor(int **table);
int					ft_size_ver(int **table);


#endif
