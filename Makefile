# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 01:21:23 by dramirez          #+#    #+#              #
#    Updated: 2023/02/27 01:49:54 by dramirez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/1_ft_check_int.c \
		src/2_ft_check_num.c \
		src/3_ft_listas_utils.c \
		src/3_ft_listas_utils2.c \
		src/4_ft_push.c \
		src/4_ft_rotar_reverso.c \
		src/4_ft_rotar.c \
		src/4_ft_swap.c \
		src/5_ft_mover.c \
		src/5_ft_posiciones_coste.c \
		src/5_ft_posiciones.c \
		src/6_ft_ordenar_3.c \
		src/6_ft_ordenar_3mas.c \
		src/6_ft_ordenar_utils.c \
		src/main.c \
		
OSRC = $(SRC:.c=.o)

AR = ar -rcs

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

all: $(NAME)

$(NAME): $(OSRC)
	make -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OSRC) -lft -L.

clean:
	make clean -C libft
	$(RM) $(OSRC)

fclean: clean
		make fclean -C libft
		$(RM) libft.a
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
