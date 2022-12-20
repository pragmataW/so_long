# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 11:00:11 by msariasl          #+#    #+#              #
#    Updated: 2022/12/20 00:23:55 by yciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
SO_LONG_FILES = $(shell find . -name "*.c" ! -name "main.c")
LIBFT_FILES = $(shell find ../libs/libft -name "*.c")

FLAGS = -Wall -Wextra -Werror

$(NAME): $(SO_LONG_FILES) $(LIBFT_FILES) main.c
		@gcc $(FLAGS) -c $(LIBFT_FILES) $(SO_LONG_FILES)
		@ar -rcs $(NAME) *.o
		@rm -rf *.o

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

debug: $(NAME)
	@gcc $(FLAGS) main.c $(NAME) && ./a.out