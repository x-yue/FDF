# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 14:59:23 by yuxu              #+#    #+#              #
#    Updated: 2018/09/10 14:04:52 by yuxu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

CC				=	gcc

SRCS			=	srcs/fdf.c srcs/convert.c srcs/map.c srcs/errors.c \
					srcs/manip.c srcs/color.c srcs/link.c srcs/dots.c \
					srcs/index.c \

CFLAGS			=	-Wall -Werror -Wextra
FLAGS			=	-L /usr/include -lmlx -framework OpenGL -framework Appkit -g3

_LIBFT			=	srcs/libft/libft.a
_MINILIBX		=	srcs/minilibx_macos/libmlx.a
_LIBFT_DIR		=	srcs/libft
_MINILIBX_DIR	=	srcs/minilibx_macos

OBJS 		=	$(SRCS: .c = .o)

all: $(NAME)
#	make -C $(_MINILIBX_DIR)
#	make -C $(_LIBFT_DIR)

$(NAME):
		clang -I /usr/local/include $(SRCS) $(FLAGS)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o

clean:
		/bin/rm -f $(OBJS)
#		/bin/rm srcs/minilibx_macos/*.o
#		/bin/rm srcs/libft/*.o

fclean: clean
		/bin/rm a.out
#		/bin/rm srcs/minilibx_macos/libmlx.a
#		/bin/rm srcs/libft/libft.a

re: fclean all
