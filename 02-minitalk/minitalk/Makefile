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

SERVER = server
CLIENT = client
CC = @gcc
CFLAGS =  -Wall -Werror -Wextra
LIBFT = libft

SRC	=	server.c	\
		client.c

OBJ = $(SRC:.c=.o)

#------------ Server & Client section -----------

all: $(SERVER) $(CLIENT)

#-l(library) & -L(dir)
#$@ filename-target
#$< filename-1stPrerequisite

$(SERVER): $(SERVER).o $(LIBFT)
	$(CC) -o $@ $< -Llibft -lft

$(CLIENT): $(CLIENT).o $(LIBFT)
	$(CC) -o $@ $< -Llibft -lft

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

#------------- Libft section ----------------

$(LIBFT):
	make -C libft

#------------- Clean section------------------

clean:
	@rm -f $(OBJ)
	make -C libft clean

fclean: clean
	@rm -f $(SERVER) $(CLIENT) libft/libft.a

re: fclean all


.PHONY : all clean fclean re libft
