# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:58:57 by ppolozhe          #+#    #+#              #
#    Updated: 2019/03/06 18:18:11 by ppolozhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ppolozhe.filler
LIBFT = libft/
CFLAGS  = -Wall -Wextra -Werror
CC = @gcc
FILLER_H = -I filler.h
VISUAL = -lmlx -lm -framework OpenGL -framework AppKit

SRC = main.c parse.c rape_map.c algorithm.c help_algo.c

OBJ = $(SRC:.c=.o)

LIBA = $(addprefix $(LIBFT), libft.a)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(VISUAL) $(SRC) $(FILLER_H) $(LIBA) -o $(NAME)
	@echo "\x1B[35m\0binary file |-- ppolozhe.filler --| is created\x1B[0m\0"

clean:
		@make clean -C $(LIBFT)
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C $(LIBFT)
		@rm -f $(NAME)

re: fclean all
