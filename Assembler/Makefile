# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 20:36:32 by fbonnin           #+#    #+#              #
#    Updated: 2017/08/23 18:23:04 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

NAMES = \
main \
bytecode \
line \
strings \
instruction \
parsing1 \
parsing2 \
declaration \
call \
op

O_FILES = $(addsuffix .o, $(addprefix src/, $(NAMES)))

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C src/libft
	$(CC) $(CFLAGS) $(O_FILES) src/libft/libft.a -o $(NAME)
	@echo "ASM:\033[92m OK\033[0m"

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@make -C src/libft clean
	@rm -rf $(O_FILES)

fclean: clean
	@make -C src/libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
