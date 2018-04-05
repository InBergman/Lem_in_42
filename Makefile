# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/11 22:46:03 by Macintosh         #+#    #+#              #
#    Updated: 2016/11/03 19:33:57 by mberedda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =	main.c \
		browse_way.c \
		check_arcs.c \
		check_associability.c \
		check_start.c \
		check_way.c \
		dijkstra.c \
		free_list.c \
		print.c \
		read_standard_input.c \
		tools.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

CC = gcc

.SILENT:

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L libft -lft

lib:
	@make -C libft

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all lib clean fclean re
