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
CC=gcc

CFLAGS += -Wall -Wextra -Werror

SRCS =	src/ft_printf.c			\
		src/bin.c				\
		src/check.c				\
		src/conv_for_c.c		\
		src/conv_for_d.c		\
		src/conv_for_o.c		\
		src/conv_for_p.c		\
		src/conv_for_s.c		\
		src/conv_for_u.c		\
		src/conv_for_x.c		\
		src/flags.c				\
		src/ft_atoi.c			\
		src/ft_bzero.c			\
		src/ft_isdigit.c		\
		src/ft_itoa.c			\
		src/ft_nb_digit.c		\
		src/ft_putchar.c		\
		src/ft_putnbr.c			\
		src/ft_putstr.c			\
		src/ft_putwchar.c		\
		src/ft_strcpy.c			\
		src/ft_strsplit.c		\
		src/ft_strlen.c			\
		src/hexa.c				\
		src/octal.c				\
		src/precision.c			\
		src/print.c				\
		src/unicode.c

INC_FILES = include/ft_printf.h		\
			include/struct.h


C_INCLUDE_PATH += include/

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

all: $(NAME)

MKDIR ?= mkdir

obj/%.o: src/%.c $(INC_FILES)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $^


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) -rf obj

re: fclean all
