/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:59:01 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/07 15:36:43 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdint.h"
# include "wchar.h"

# define PRINTF_BUFFER_SIZE 1000
# define PRINTF_MAX_WIDTH_LEN 10
# define PRINTF_MAX_PRECISION_LEN 10
# define PRINTF_ERROR -1

typedef struct	s_printf
{
	int						output;

	const unsigned char		*format;
	int						i_format;
	va_list					params;
	int						nb_bytes_written;
	int						nb_chars_written;
	unsigned char			buffer[PRINTF_BUFFER_SIZE];
	int						i_buffer;

	int						flag_minus;
	int						flag_zero;
	int						flag_sharp;
	int						flag_plus;
	int						flag_space;
	int						width;
	int						precision;
	int						size;
	unsigned char			type;

	wchar_t					c;

	unsigned char			*str;
	wchar_t					*wstr;
	int						len_str;

	unsigned long long int	ullint;
	long long int			llint;
	int						base;
	int						uppercase;
	unsigned char			prefix[2];
	int						len_prefix;
	int						len_number;
	int						nb_zeroes;

	char					*bits;
	int						nb_bits;
	int						i_bit;
	char					utf8[9];
	int						i_utf8;
}				t_printf;

int				ft_printf(int output, const char *format, ...);
int				ft_put_wchar_to_buffer(t_printf *s, unsigned int c, int w);

void			ft_get_flags(t_printf *s);
int				ft_get_width(t_printf *s);
int				ft_get_precision(t_printf *s);
void			ft_get_size_modifier(t_printf *s);
void			ft_get_size_modifier_2(t_printf *s, const unsigned char *size);

int				ft_printf_c(t_printf *s, int w);
int				ft_type_c(t_printf *s);

int				ft_printf_str(t_printf *s);
int				ft_printf_wstr(t_printf *s);
int				ft_type_str(t_printf *s);
void			ft_null_str(unsigned char *null_str, wchar_t *null_wstr);

int				ft_printf_ullint(t_printf *s);
int				ft_printf_ullint_2(t_printf *s, unsigned char *number);
int				ft_type_uint(t_printf *s);
int				ft_type_uint_2(t_printf *s);

int				ft_printf_llint(t_printf *s);
int				ft_type_int(t_printf *s);

void			ft_type_n(t_printf *s);
void			ft_type_n_2(t_printf *s);

int				ft_type_unknown(t_printf *s);

void			ft_put_utf8_to_buffer(t_printf *s);
int				ft_size_wchar(wchar_t c);

#endif
