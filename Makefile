# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/19 17:52:02 by plogan            #+#    #+#              #
#    Updated: 2017/08/19 17:54:30 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: makelibs

makelibs:
	@make -C ASM
	@make -C VM

clean:
	@make -C ASM clean
	@make -C VM clean

fclean: clean
	@make -C ASM fclean
	@make -C VM fclean

re: fclean all

.PHONY: all clean fclean re
