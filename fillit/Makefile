# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yharkati <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 10:40:26 by yharkati          #+#    #+#              #
#    Updated: 2019/03/02 11:37:55 by modaouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = parsing.c fillit.c ft_backtrack.c main.c ft_utile.c ft_tofree.c

OBJ = $(SRC:.c=.o)

NAME = fillit

CC = gcc

LIBFT = libft

CF = -Wall -Wextra -Werror

.PHONY: all fclean re clean

all: $(LIBFT) $(NAME)

$(NAME): Makefile $(OBJ) $(LIBFT)
	make -C $(LIBFT) all
	$(CC) $(CF) -c $(SRC)
	$(CC) $(CF) $(OBJ) libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean:
	rm -f $(OBJ)
	rm -f ./$(NAME)
	make -C $(LIBFT) fclean

re: $(LIBFT)
	rm -f $(OBJ)
	rm -f ./$(NAME)
	make -C $(LIBFT) fclean
	make -C $(LIBFT) all
	$(CC) $(CF) -c $(SRC)
	$(CC) $(CF) $(OBJ) libft/libft.a -o $(NAME)
