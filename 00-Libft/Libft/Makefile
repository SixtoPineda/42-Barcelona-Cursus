# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:47:12 by spineda-          #+#    #+#              #
#    Updated: 2022/01/25 21:40:13 by syxtyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @gcc
CFLAGS =  -Wall -Werror -Wextra
INCLUDE = libft.h
AR = @ar
ARFLAGS = -rcs
RANLIB = @ranlib

SRC	=	ft_atoi.c	\
		ft_bzero.c	\
		ft_calloc.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c	\
		ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstclear.c	\
		ft_lstdelone.c	\
		ft_lstiter.c	\
		ft_lstlast.c	\
		ft_lstmap.c	\
		ft_lstnew.c	\
		ft_lstsize.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c	\
		ft_strchr.c	\
		ft_strdup.c	\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c	\
		ft_strmapi.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c	\
		ft_tolower.c	\
		ft_toupper.c
OBJ = $(SRC:.c=.o)

BONUS =	ft_lstnew.c	\
		ft_lstadd_front.c	\
		ft_lstsize.c	\
		ft_lstlast.c	\
		ft_lstadd_back.c	\
		ft_lstdelone.c	\
		ft_lstclear.c	\
		ft_lstiter.c	\
		ft_lstmap.c
BONUSOBJ = $(BONUS:.c=.o)

#------------Lib section-----------

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

bonus: $(NAME) $(BONUSOBJ)
	$(AR) $(ARFLAGS) $(NAME) $(BONUSOBJ)
	$(RANLIB) $(NAME)

%.o:%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

#------------Clean section-----------

clean:
	@rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY : all clean fclean re bonus rebonus
