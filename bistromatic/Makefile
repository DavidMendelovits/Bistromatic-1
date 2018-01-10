# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 14:43:58 by ttran             #+#    #+#              #
#    Updated: 2018/01/09 14:28:20 by ttran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc
FLAGS = -Wall -Werror -Wextra
CC = gcc
SRCS = srcs/main.c srcs/misc.c srcs/miscput.c srcs/recursive_descent_parser.c 

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -o $(NAME) -I includes $(SRCS)

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
