# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 23:22:35 by wasman            #+#    #+#              #
#    Updated: 2016/12/30 23:26:22 by wasman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
BLDLIB = ar rc
SORT = ranlib

SOURCES =	ft_printf.c\


OBJ =	$(SOURCES:.c=.o)

.PHONY: all norm clean fclean re

$(NAME):
	$(CC) -c $(CFLAGS) $(SOURCES)
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
