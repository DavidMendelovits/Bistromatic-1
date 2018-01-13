# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 14:43:58 by ttran             #+#    #+#              #
#    Updated: 2018/01/12 20:31:55 by ttran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc
FLAGS = -Wall -Werror -Wextra
CC = gcc
SRCS = srcs/main.c srcs/misc.c srcs/miscput.c srcs/recursive_descent_parser.c \
	   srcs/mod_bignum.c srcs/mult_bignum.c srcs/sub_bignum.c \
	   srcs/add_bignum.c srcs/div_bignum.c srcs/funcs_bignum.c \
	   srcs/miscset.c srcs/misc2.c\

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -o $(NAME) -I includes $(SRCS)

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
