# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 14:25:58 by nicorodr          #+#    #+#              #
#    Updated: 2026/02/24 15:20:55 by nicorodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Solo los archivos que hemos programado hasta ahora:
SRC =	main.c \
		utils.c \
		lists_utils.c \
		ft_split.c \
		operations.c \
		swap.c \
		push.c \
		rotate.c \
		reverse.c \
		sort.c \
		sort_utils.c \
		moves.c \
		position.c \
		cost.c \
		r_both.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re