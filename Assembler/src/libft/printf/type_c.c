/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:24:36 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 19:28:12 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_width(t_printf *s)
{
	int i;

	if (!s->flag_minus)
	{
		if (s->flag_zero)
			s->nb_zeroes = ft_max(s->width - 1, 0);
		else
		{
			i = 0;
			while (i < s->width - 1)
			{
				if (ft_put_wchar_to_buffer(s, ' ', 0) == PRINTF_ERROR)
					return (PRINTF_ERROR);
				i++;
			}
		}
	}
	return (0);
}

static int	ft_flag_minus(t_printf *s)
{
	int i;

	if (s->flag_minus)
	{
		i = 0;
		while (i < s->width - 1)
		{
			if (ft_put_wchar_to_buffer(s, ' ', 0) == PRINTF_ERROR)
				return (PRINTF_ERROR);
			i++;
		}
	}
	return (0);
}

int			ft_printf_c(t_printf *s, int w)
{
	int i;

	if (ft_width(s) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	i = 0;
	while (i++ < s->nb_zeroes)
		if (ft_put_wchar_to_buffer(s, '0', 0) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	if (ft_put_wchar_to_buffer(s, s->c, w) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	if (ft_flag_minus(s) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	return (0);
}

int			ft_type_c(t_printf *s)
{
	int w;

	if (s->type != 'c' && s->type != 'C' && s->type != '%')
		return (0);
	w = 0;
	if (s->type == '%')
		s->c = '%';
	else if (s->type == 'C' || s->size == 1)
	{
		s->c = va_arg(s->params, wint_t);
		w = 1;
	}
	else
		s->c = (unsigned char)(char)va_arg(s->params, int);
	return (ft_printf_c(s, w));
}
