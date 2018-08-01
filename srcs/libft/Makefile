# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 03:41:02 by yuxu              #+#    #+#              #
#    Updated: 2018/04/30 14:34:49 by yuxu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =            libft.a

CC =            gcc
FLAGS =            -Wall -Werror -Wextra

COMPILED =      ft_atoi.o \
       ft_bzero.o \
       ft_isalnum.o \
       ft_isalpha.o \
       ft_isascii.o \
       ft_isdigit.o \
       ft_isprint.o \
       ft_itoa.o \
       ft_tolower.o \
       ft_strtrim.o \
       ft_memalloc.o \
       ft_memccpy.o \
       ft_memchr.o \
       ft_memcmp.o \
       ft_memcpy.o \
       ft_memdel.o \
       ft_memmove.o \
       ft_memset.o \
       ft_toupper.o \
       ft_strncat.o \
       ft_putchar.o \
       ft_putchar_fd.o \
       ft_putendl.o \
       ft_putnbr.o \
       ft_strnew.o \
       ft_strstr.o \
       ft_strrchr.o \
       ft_strmap.o \
       ft_strlcat.o \
       ft_strncpy.o \
       ft_strlen.o \
       ft_strmapi.o \
       ft_strnstr.o \
       ft_strncmp.o \
       ft_striter.o \
       ft_strsplit.o \
       ft_strequ.o \
       ft_strnequ.o \
       ft_striteri.o \
       ft_strcpy.o \
       ft_strcmp.o \
       ft_strjoin.o \
       ft_strsub.o \
       ft_strclr.o \
       ft_strchr.o \
       ft_strcat.o \
       ft_strdel.o \
       ft_putstr_fd.o \
       ft_putstr.o \
       ft_putnbr_fd.o \
       ft_putendl_fd.o \
       ft_lstnew.o \
       ft_lstdelone.o \
       ft_lstdel.o \
       ft_lstadd.o \
       ft_lstiter.o \
       ft_lstmap.o \
       ft_partlen.o \
       ft_swap.o \
       ft_sort_int_tab.o \
       ft_strrev.o \
       ft_lcm.o \
       ft_pgcd.o \
       ft_split_keep_blanc.o \
       ft_index.o \
       ft_partstr.o \
       ft_strmove.o \
       ft_tablen.o \
       ft_tabjoin.o \
       ft_strdup.o \
       get_next_line.o

all: $(NAME)

$(NAME): $(COMPILED)
	ar rc $(NAME) $(COMPILED)
	ranlib $(NAME)

$(COMPILED): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all
