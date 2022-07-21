# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 21:26:51 by wmardin           #+#    #+#              #
#    Updated: 2022/07/22 01:21:27 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

NAME =	push_swap.a
SRC =	main.c\
		util_setup.c util_operations.c util_assignrank.c\
		do_swap.c do_push.c do_rotate.c do_revrotate.c\
		algo_main.c algo_util_get.c algo_util_get1.c algo_util_check.c
OBJ =	$(SRC:.c=.o)

$(NAME): $(OBJ)
	@make -C ./libft
	
all: $(NAME)
#	$(CC) $(CFLAGS) libft/libft.a $(OBJ) main.c
	
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME) a.out

re: fclean all

test:
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o push_swap

testnoflag:
	$(CC) $(SRC) libft/libft.a