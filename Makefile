# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 22:40:16 by rlucio-l          #+#    #+#              #
#    Updated: 2021/12/09 14:19:55 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I /usr/local/include

.c.o :
	$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

NAME = so_long

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L /usr/local/lib -lmlx -lXext -lX11

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
