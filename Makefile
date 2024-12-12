# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 13:16:57 by ruida-si          #+#    #+#              #
#    Updated: 2024/12/03 13:17:02 by ruida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = push_commands.c push_order.c push_split.c push_swap.c \
	push_utils.c swap_swap.c swap_swap2.c push_order_radix.c \
	

OBJ = $(SRC:.c=.o)

NAME = push_swap.a

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

ap:
	@$(CC) $(FLAGS) $(SRC) -o push_swap

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all ap clean fclean re
