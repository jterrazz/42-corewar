# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/19 17:52:02 by plogan            #+#    #+#              #
#    Updated: 2017/08/21 15:54:10 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: makelibs

makelibs:
	@make -C Assembler
	@make -C VirtualMachine

clean:
	@make -C Assembler clean
	@make -C VirtualMachine clean

fclean: clean
	@make -C Assembler fclean
	@make -C VirtualMachine fclean

re: fclean all

.PHONY: all clean fclean re
