# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 22:40:16 by rlucio-l          #+#    #+#              #
#    Updated: 2021/12/17 12:19:01 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I /usr/local/include

.c.o :
	$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

LIBFT = libft.a
LIBFT_DIR = ./libft

NAME = so_long

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L. -lmlx -lXext -lX11 $(LIBFT_DIR)/$(LIBFT)

$(LIBFT) :
	make -C $(LIBFT_DIR)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re libft
