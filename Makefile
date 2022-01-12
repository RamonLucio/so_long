# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 22:40:16 by rlucio-l          #+#    #+#              #
#    Updated: 2022/01/12 18:49:53 by rlucio-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/file_control.c \
		src/measure_functions.c \
		src/move_player.c \
		src/parse_map.c \
		src/receive_events.c \
		src/render_map.c \
		src/so_long.c \
		src/utils.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I /usr/local/include

.c.o :
	$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) -L. -lmlx -lXext -lX11

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
