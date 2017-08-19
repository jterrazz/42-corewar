/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags_width_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:57:43 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 18:10:34 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ');
}

void		ft_get_flags(t_printf *s)
{
	char flag;

	s->flag_minus = 0;
	s->flag_zero = 0;
	s->flag_sharp = 0;
	s->flag_plus = 0;
	s->flag_space = 0;
	while (ft_is_flag(s->format[s->i_format]))
	{
		flag = s->format[s->i_format++];
		if (flag == '-')
			s->flag_minus = 1;
		else if (flag == '0')
			s->flag_zero = 1;
		else if (flag == '#')
			s->flag_sharp = 1;
		else if (flag == '+')
			s->flag_plus = 1;
		else if (flag == ' ')
			s->flag_space = 1;
	}
}

int			ft_get_width(t_printf *s)
{
	char	width[PRINTF_MAX_WIDTH_LEN + 1];
	int		i;

	if (s->format[s->i_format] == '*')
	{
		s->i_format++;
		s->width = va_arg(s->params, int);
		if (s->width < 0)
		{
			s->flag_minus = 1;
			s->width *= -1;
		}
		return (0);
	}
	i = 0;
	while (ft_isdigit(s->format[s->i_format]))
	{
		if (i == PRINTF_MAX_WIDTH_LEN)
			return (PRINTF_ERROR);
		width[i++] = s->format[s->i_format++];
	}
	width[i] = 0;
	s->width = ft_atoi(width);
	return (0);
}

int			ft_get_precision(t_printf *s)
{
	char	precision[PRINTF_MAX_PRECISION_LEN + 1];
	int		i;

	if (s->format[s->i_format] != '.')
	{
		s->precision = -1;
		return (0);
	}
	s->i_format++;
	if (s->format[s->i_format] == '*')
	{
		s->i_format++;
		s->precision = va_arg(s->params, int);
		return (0);
	}
	i = 0;
	while (ft_isdigit(s->format[s->i_format]))
	{
		if (i == PRINTF_MAX_PRECISION_LEN)
			return (PRINTF_ERROR);
		precision[i++] = s->format[s->i_format++];
	}
	precision[i] = 0;
	s->precision = ft_atoi(precision);
	return (0);
}
