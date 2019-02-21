# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:58:57 by ppolozhe          #+#    #+#              #
#    Updated: 2019/02/21 16:58:59 by ppolozhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ppolozhe.filler
LIBFT = libft/
CFLAGS  = -Wall -Wextra -Werror
CC = gcc
FILLER_H = filler.h

SRC = main.c parse.c

OBJ = $(SRC:.c =.o)

LIBA = $(addprefix $(LIBFT), libft.a)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBA) -o $(NAME)



clean:
		make clean -C libft/
		rm -rf $(OBJ)

fclean: clean
		make fclean -C libft/
		rm -rf $(NAME)

re: fclean all
