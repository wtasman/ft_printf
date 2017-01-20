# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasman <wasman@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 23:22:35 by wasman            #+#    #+#              #
#    Updated: 2017/01/04 18:35:45 by wasman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
BLDLIB = ar rc
SORT = ranlib

SOURCES =	ft_printf.c\
			ft_isdigit.c\
			ft_itoa_base.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_strlen.c

OBJ =	$(SOURCES:.c=.o)

.PHONY: all norm clean fclean re

$(NAME): $(LIBS) $(OBJ)
	$(CC) -c $(CFLAGS) $(SOURCES) $(LIB)
	$(BLDLIB) $(NAME) $(OBJ)
	$(SORT) $(NAME)

all: $(NAME)

norm: fclean
	norminette $(SOURCES)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f rm $(NAME)

re: fclean all
