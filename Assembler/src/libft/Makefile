# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 16:58:47 by fbonnin           #+#    #+#              #
#    Updated: 2017/08/19 17:50:32 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BASIC_NAMES = \
ft_atoi \
ft_bzero \
ft_get_next_line \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_islower \
ft_isprint \
ft_isupper \
ft_itoa \
ft_lstadd \
ft_lstdel \
ft_lstdelone \
ft_lstiter \
ft_lstmap \
ft_lstnew \
ft_lst_push_back \
ft_max \
ft_memalloc \
ft_memccpy \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memdel \
ft_memmove \
ft_memset \
ft_min \
ft_putchar \
ft_putchar_fd \
ft_putendl \
ft_putendl_fd \
ft_putnbr \
ft_putnbr_fd \
ft_putstr \
ft_putstr_fd \
ft_stolower \
ft_stoupper \
ft_strcat \
ft_strchr \
ft_strclr \
ft_strcmp \
ft_strcpy \
ft_strdel \
ft_strdup \
ft_strequ \
ft_striter \
ft_striteri \
ft_strjoin \
ft_strlcat \
ft_strlen \
ft_strmap \
ft_strmapi \
ft_strncat \
ft_strncmp \
ft_strncpy \
ft_strnequ \
ft_strnew \
ft_strnstr \
ft_strrchr \
ft_strsplit \
ft_strstr \
ft_strsub \
ft_strtrim \
ft_tolower \
ft_toupper

SIMPLE_NAMES = \
ft_ullint_to_str \
ft_str_to_llint \
ft_str_to_ullint

PRINTF_NAMES = \
ft_printf \
get_flags_width_precision \
get_size_modifier \
type_c \
type_str \
printf_ullint \
type_uint \
type_int \
type_n \
type_unknown \
utf8 \
utf8_2

CC = @gcc

BASIC_FILES = $(addprefix basic/, $(BASIC_NAMES))
SIMPLE_FILES = $(addprefix simple/, $(SIMPLE_NAMES))
PRINTF_FILES = $(addprefix printf/, $(PRINTF_NAMES))

ALL_FILES = \
$(BASIC_FILES) \
$(SIMPLE_FILES) \
$(PRINTF_FILES)

O_FILES = $(addsuffix .o, $(ALL_FILES))

$(NAME): $(O_FILES)
	@ar rc $(NAME) $(O_FILES)

all: $(NAME) $(O_FILES)
%.o: %.c
	$(CC) -c $< -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf $(O_FILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
