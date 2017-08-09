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
LIBFT = libft
LIB = libft/libft.a
SORT = ranlib
TEMP = temp.a

SOURCES =	ft_printf.c\
			ft_itoa_base.c\
			ft_putwchar.c\
			ft_putwstr.c\
			c_spec.c\
			checks.c\
			d_spec.c\
			ft_itoa_base.c\
			ft_printf.c\
			inits.c\
			is_checks.c\
			o_spec.c\
			p_spec.c\
			s_spec.c\
			u_spec.c\
			x_spec.c\

OBJ =	$(SOURCES:.c=.o)

.PHONY: all norm clean fclean re

$(NAME): $(LIBS) $(OBJ)
	$(CC) -c $(CFLAGS) $(SOURCES)
	$(MAKE) -C $(LIBFT)
	$(BLDLIB) $(NAME) $(OBJ) $(LIBFT)/$(OBJ)
	$(SORT) $(NAME)

all: $(NAME)

norm: fclean
	norminette $(SOURCES)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f rm $(NAME)

re: fclean all
