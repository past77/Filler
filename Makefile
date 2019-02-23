# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:58:57 by ppolozhe          #+#    #+#              #
#    Updated: 2019/02/22 14:25:09 by ppolozhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ppolozhe.filler
LIBFT = libft/
CFLAGS  = -Wall -Wextra -Werror
CC = @gcc
FILLER_H = -I filler.h

SRC = main.c parse.c rape_map.c

OBJ = $(SRC:.c=.o)

LIBA = $(addprefix $(LIBFT), libft.a)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(FILLER_H) $(LIBA) -o $(NAME)
	@echo "\x1B[35m\0binary file |-- ppolozhe.filler --| is created\x1B[0m\0"

clean:
		@make clean -C $(LIBFT)
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C $(LIBFT)
		@rm -f $(NAME)

re: fclean all
