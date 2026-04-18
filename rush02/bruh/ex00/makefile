# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saljawab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 19:30:48 by saljawab          #+#    #+#              #
#    Updated: 2026/04/18 19:37:59 by saljawab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = main.c dict_parser.c number_handler.c string_functions.c validators.c file_handler.c

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

re: fclean all
