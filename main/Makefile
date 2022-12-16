# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 11:00:11 by msariasl          #+#    #+#              #
#    Updated: 2022/12/16 11:28:16 by yciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FILES = $(shell find . -name *.c)
LIBS = $(shell find ../libs/minilibx/libmlx.a)
OBJ = ($(FILES:.o=.c))
CC = gcc -Wall -Wextra -Werror

$(NAME): $(FILES)
	$(CC) $(FILES) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)
	
all: $(NAME)

clean:
	rm -rf *.o
	
fclean: clean
	rm -rf $(NAME)

re:	fclean all

debug:
	make && ./$(NAME)

