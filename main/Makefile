# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 11:00:11 by msariasl          #+#    #+#              #
#    Updated: 2023/01/20 15:44:06 by yciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
SO_LONG_FILES = $(shell find . -name "*.c" ! -name "so_long.c")
SO_LONG_OBJ := $(SO_LONG_FILES:%.c=%.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

$(NAME): $(SO_LONG_FILES) $(SO_LONG_OBJ)
		@make -C ../libs/minilibx
		@make -C ../libs/libft
		@cp ../libs/minilibx/libmlx.a .
		@cp ../libs/libft/libft.a .
		@ar -rcs $(NAME) *.o
		@gcc $(FLAGS) -o so_long so_long.c libmlx.a so_long.a libft.a -framework OpenGL -framework AppKit
		@rm -rf libft.a libmlx.a so_long.a

all: $(NAME)

clean:
	@rm -rf *.o
	@make clean -C ../libs/minilibx/
	@make clean -C ../libs/libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf so_long

re: fclean $(NAME)

debug: $(NAME)
	@gcc $(FLAGS) so_long.c $(NAME) && ./a.out
