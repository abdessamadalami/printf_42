# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 08:53:37 by ael-oual          #+#    #+#              #
#    Updated: 2021/11/23 08:54:46 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = ft_printf.c ft_print_memory.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c  
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
clean: 
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME) 
re:fclean all 