# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/19 17:12:35 by plogan            #+#    #+#              #
#    Updated: 2017/08/21 15:51:24 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

SRC_NAME = src/check_op.c src/error.c src/init_flags.c src/launch_processes.c \
		   src/print.c src/check_players.c src/free.c src/init_players.c \
		   src/main.c src/run_processes_1.c src/check_processes.c \
		   src/init_arena.c src/init_processes.c src/parse_args.c \
		   src/run_processes_2.c \
		   ft_op/getters.c ft_op/op.c ft_op/op_aff.c ft_op/op_fork.c \
		   ft_op/op_ldi.c ft_op/op_live.c ft_op/op_lldi.c ft_op/op_st.c \
		   ft_op/op_sub.c ft_op/op_zjmp.c ft_op/helpers.c ft_op/op_add.c \
		   ft_op/op_and.c ft_op/op_ld.c ft_op/op_lfork.c ft_op/op_lld.c \
		   ft_op/op_or.c ft_op/op_sti.c ft_op/op_xor.c ft_op/get_value_for_var.c

OFILES = $(SRC_NAME:.c=.o)

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

all: makelibs $(NAME)

makelibs:
	@make -C libs/libft

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) libs/libft/libft.a \
		libs/libft/ft_printf/libftprintf.a -o $(NAME)
	@echo "VM:\033[92m OK\033[0m"

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes

clean:
	@make -C libs/libft clean
	@rm -rf $(OFILES)

fclean: clean
	@make -C libs/libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
