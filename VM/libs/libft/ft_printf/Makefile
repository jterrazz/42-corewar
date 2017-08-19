# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/12 15:20:52 by jterrazz          #+#    #+#              #
#    Updated: 2017/08/19 17:40:34 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = @gcc

SRC_PATH = ./src

SRC_NAME = ft_printf.c \
		   dispatch.c flags.c \
		   ft_itoa_base.c render_char.c render_hex.c render_nbr.c \
		   ft_uitoa_base.c \
		   render_octal.c render_pointer.c render_str.c render_unsigned.c \
		   get_uintmax.c get_intmax.c display.c checker.c render_double.c \
		   flags_init.c conv_init.c


SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OFILES = $(SRC_NAME:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes -I ../../../includes

clean:
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
