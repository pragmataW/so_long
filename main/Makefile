# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 11:00:11 by msariasl          #+#    #+#              #
#    Updated: 2022/12/20 08:50:15 by yciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
SO_LONG_FILES = $(shell find . -name "*.c" ! -name "so_long.c")
LIBFT_FILES = $(shell find ../libs/libft -name "*.c")

FLAGS = -Wall -Wextra -Werror

$(NAME): $(SO_LONG_FILES) $(LIBFT_FILES) so_long.c
		@gcc $(FLAGS) -c $(LIBFT_FILES) $(SO_LONG_FILES)
		@ar -rcs $(NAME) *.o
		@rm -rf *.o

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

debug: $(NAME)
	@gcc $(FLAGS) so_long.c $(NAME) && ./a.out