/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:10:17 by yuxu              #+#    #+#             */
/*   Updated: 2018/09/06 00:29:44 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
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
	int				line;
	int				col;
	int				value;
	int				color;
	int				hor;
	int				ver;
	int				index_hor;
	int				index_ver;
	int				hor_right;
	int				ver_right;
	int				hor_under;
	int				ver_under;
	int				x;
	int				y;
	int				dist_hor;
	int				dist_ver;
}					t_draw;

char				*readfile(int fd);
void				paint(void *mlx_ptr, void *win_ptr, int **table,
					char *content);
int					deal_key(int key, void *param);
int					color(int value);
int					**treatfile(char *content);
int					error_check(int fd, char *content, int **table);
void				ft_link(int **table, char *content, int line, int col);
int					ft_size_hor(int **table);
int					ft_size_ver(int **table);
int					ft_max_int(int **table);
int					hor_map(int **table);
int					ver_map(int **table);
int					hor_loc(int **table, int line, int col, int index);
int					ver_loc(int **table, int line, int col, int index);
int					fdf_index_hor(int **table);
int					fdf_index_ver(int **table);
void				fdf_link(void *mlx_ptr, void *win_ptr, int **table,
					t_draw d);

#endif
