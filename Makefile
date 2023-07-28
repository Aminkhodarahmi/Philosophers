# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 15:59:31 by akhodara          #+#    #+#              #
#    Updated: 2023/07/02 13:51:34 by akhodara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./src/philo.c \
	./src/ft_error.c \
	./src/ft_handle_input.c \
	./src/ft_init.c \
	./src/ft_threads.c \
	./src/ft_action.c \
	./src/ft_print.c \
	./src/ft_time.c \
	./src/ft_join_destroy.c \
	./src/ft_check_death.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -pthread

all: $(NAME)

	@echo ""
	@echo ""
	@echo "compiling done. Now you have a big shell 😜"
	@echo ""
	@echo ""
	@echo "Have Written by ***  Amin Khodarahmi  ***"
	@echo ""
	@echo ""
	@curl https://icanhazdadjoke.com
	@echo ""
	@echo ""

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -pthread

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
