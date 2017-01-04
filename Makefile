# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasman <wasman@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 23:22:35 by wasman            #+#    #+#              #
#    Updated: 2017/01/04 13:58:32 by wasman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
BLDLIB = ar rc
SORT = ranlib
LIBS = libft/libft.a

SOURCES =	ft_printf.c\

OBJ =	$(SOURCES:.c=.o)

.PHONY: all norm clean fclean re

$(NAME):
	$(CC) -c $(CFLAGS) $(SOURCES) 
	$(BLDLIB) $(NAME) $(OBJ) $(LIBS)
	$(SORT) $(NAME)

all: $(NAME)

norm: fclean
	norminette $(SOURCES)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f rm $(NAME)

re: fclean all
