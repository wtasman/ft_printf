
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:26:58 by wasman            #+#    #+#              #
#    Updated: 2016/09/21 13:37:49 by wasman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
BLDLIB = ar rc
SORT = ranlib

SOURCES =	ft_putchar.c\
			ft_putstr.c\
			ft_putnbr.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_isspaces.c\
			ft_putendl.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strlen.c\
			ft_putstr_fd.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_atoi.c\
			ft_swap.c\
			ft_strrev.c\
			ft_memset.c\
			ft_memmove.c\
			ft_memcpy.c\
			ft_memcpy_rev.c\
			ft_bzero.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memalloc.c\
			ft_strdup.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strclr.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_memdel.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strstr.c\
			ft_strtrim.c\
			ft_strnstr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strjoin.c\
			ft_strsub.c\
			ft_isspace.c\
			ft_itoa.c\
			ft_isspace.c\
			ft_wordcount.c\
			ft_strdtrim.c\
			ft_strsplit.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstiter.c\
			ft_lstadd.c\
			ft_lstmap.c\
			ft_isupper.c\
			ft_islower.c\
			ft_sort_list.c\
			get_next_line.c

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
