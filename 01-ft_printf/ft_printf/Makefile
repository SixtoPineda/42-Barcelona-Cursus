# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:47:12 by spineda-          #+#    #+#              #
#    Updated: 2022/02/02 09:53:18 by spineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = @gcc
CFLAGS =  -Wall -Werror -Wextra
INCLUDE = ft_printf.h
AR = @ar
ARFLAGS = -rcs
RANLIB = @ranlib

SRC	=	ft_printf.c	\
		ft_putchar.c	\
		ft_strncmp.c	\
		ft_itoa.c	\
		ft_strlen.c
OBJ = $(SRC:.c=.o)


#------------Lib section-----------

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

%.o:%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

#------------Clean section-----------

clean:
	@rm -f $(OBJ) 
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus rebonus
