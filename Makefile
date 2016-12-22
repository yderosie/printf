# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 16:04:33 by yderosie          #+#    #+#              #
#    Updated: 2016/12/22 15:12:39 by yderosie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = 
#-Wall -Wextra -Werror

FILES = ft_printf \
		ft_atoi \
		ft_bzero \
		ft_isalpha \
		ft_isdigit \
		ft_itoa \
		ft_itoa_u \
		ft_itoa_uli \
		ft_nb_digit \
		ft_putchar \
		ft_putnbr \
		ft_putstr \
		ft_putwchar \
		ft_putwstr \
		ft_strcpy \
		ft_strlen \
		ft_strsplit \
		flags \
		bin \
		hexa \
		octal

SRCS = $(addsuffix .c, $(FILES))
OBJ = $(SRCS:%.c=obj/%.o)

.PHONY: all clean fclean re
.SILENT: dirobj clean fclean re all $(NAME)

all: dirobj $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

obj/%.o: %.c
	$(CC) $(CFLAGS) -I./ -o $@ -c $^

clean:
	test ! -d obj || \
		rm -rf obj

fclean: clean
	test ! -f $(NAME) || \
		rm -f $(NAME)

re: fclean all

dirobj:
	test -d obj || \
		mkdir -p obj
