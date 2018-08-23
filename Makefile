# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 14:59:23 by yuxu              #+#    #+#              #
#    Updated: 2018/08/23 16:06:33 by yuxu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = srcs/fdf.c srcs/convert.c srcs/map.c srcs/errors.c \
		srcs/manip.c srcs/color.c srcs/link.c srcs/libft/libft.a \
		srcs/draw.c
FLAGS = -L /usr/include -lmlx -framework OpenGL -framework Appkit -g3

all: $(NAME)
	make -C minilibx_macos

$(NAME):
		clang -I /usr/local/include $(SRCS) $(FLAGS)

clean:
		/bin/rm minilibx_macos/*.o

fclean: clean
		/bin/rm a.out
		/bin/rm minilibx_macos/libmlx.a

re: fclean all
