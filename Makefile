# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 15:49:19 by yuxu              #+#    #+#              #
#    Updated: 2018/09/10 17:46:22 by yuxu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

DEBUG		= -g3
CC			= gcc -Wall -Werror -Wextra
LIBFTDIR	= srcs/libft
MINILIBX	= srcs/minilibx_macos
LIB			= libft.a
LIBX		= libmlx.a
HEADERLIB	= $(LIBFTDIR)
HEADERLIBX	= $(MINILIBX)
INCLUDES	= includes
LDFLAGS		= -L$(LIBFTDIR) -lft -framework OpenGL -framework AppKit \
			  -L$(MINILIBX) -lmlx
CCINCLUDES	= -I$(HEADERLIB) -I$(INCLUDES) -I$(HEADERLIBX)
HEADERS		= $(INCLUDES)/fdf.h
SRCSDIR		= srcs
OBJSDIR		= objects
SRC			= fdf.c color.c convert.c dots.c index.c manip.c map.c link.c

OBJ			= $(SRC:%.c=%.o)
	SRCS	= $(addprefix $(SRCSDIR)/, $(SRC))
	OBJS	= $(addprefix $(OBJSDIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(LIBFTDIR)/$(LIB) $(MINILIBX)/$(LIBX) $(OBJSDIR) $(OBJS)
		 $(CC) $(LDFLAGS) $(CCINCLUDES) $(OBJS) -o $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< $(CCINCLUDES)

$(LIBFTDIR)/$(LIB):
	@make -C $(LIBFTDIR)/

$(MINILIBX)/$(LIBX):
	@make -C $(MINILIBX)/

$(OBJSDIR):
	@mkdir -p objects/

clean:
	@/bin/rm -rf $(OBJSDIR);
	@make clean -C $(LIBFTDIR)
	@make clean -C $(MINILIBX)

fclean: clean
	@echo "${RED}Purge $(NAME)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@rm -rf $(NAME).dSYM

re: fclean all

.PHONY: all, clean, fclean, re, $(LIBD)

.SUFFIXES: .c .o
