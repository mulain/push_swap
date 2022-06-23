# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 21:26:51 by wmardin           #+#    #+#              #
#    Updated: 2022/06/21 09:36:03 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

NAME =	push_swap.a
SRC =	main.c errorchecking.c
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
	$(CC) $(CFLAGS) $(SRC) libft/libft.a

testnoflag:
	$(CC) $(SRC)