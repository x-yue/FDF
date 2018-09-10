/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:10:17 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/10 21:53:08 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "../srcs/minilibx_macos/mlx.h"
# include "../srcs/libft/libft.h"
# include <fcntl.h>
# include <OpenGL/gl3.h>

# define BUFF_SIZE 100
# define K_EXIT 53

typedef	struct		s_fdf
{
	char			*content;
	int				**table;
	void			*mlx_ptr;
	void			*win_ptr;
	int				size_hor;
	int				size_ver;
	int				map_size_hor;
	int				map_size_ver;
}					t_fdf;

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
	int				line;
	int				col;
	int				value;
	int				color;
	int				hor;
	int				ver;
	int				index_hor;
	int				index_ver;
	int				line_max;
	int				col_max;
	int				max_int;
}					t_draw;

typedef	struct		s_line
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dis_x;
	int				dis_y;
	int				inc_x;
	int				inc_y;
	int				err;
	int				e;
	int				value;
}					t_line;

void				paint(t_fdf f);
int					deal_key(int key);
int					map_size(int size, int hor_ver);
int					color(int value);
int					**treatfile(char *content);
void				ft_link(int **table, char *content, int line, int col);
int					ft_size_hor(int **table);
int					ft_size_ver(int **table);
int					hor_loc(t_fdf f, int line, int col, t_draw d);
int					ver_loc(t_fdf f, int line, int col, t_draw d);
int					ft_max_int(int **table);
int					hor_map(int **table);
int					ver_map(int **table);
void				fdf_link(void *mlx_ptr, void *win_ptr, t_fdf f, t_draw d);

#endif
