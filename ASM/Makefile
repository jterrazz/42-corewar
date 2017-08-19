# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 20:36:32 by fbonnin           #+#    #+#              #
#    Updated: 2017/08/19 17:51:48 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = @gcc

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

$(NAME): $(O_FILES)
	@cd src/libft && make
	$(CC) -w $(O_FILES) src/libft/libft.a -o $(NAME)
	@echo "ASM:\033[92m OK\033[0m"

all: $(NAME) $(O_FILES)
%.o: %.c
	$(CC) -w -c $< -o $@

clean:
	@cd src/libft && make clean
	@rm -f $(O_FILES)

fclean: clean
	@cd src/libft && make fclean
	@rm -f $(NAME)

re: fclean all
