/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:28:19 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 19:37:37 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_width(t_printf *s)
{
	int i;

	if (!s->flag_minus)
	{
		if (s->flag_zero)
			s->nb_zeroes = ft_max(s->width - s->len_str, 0);
		else
		{
			i = 0;
			while (s->len_str + i < s->width)
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
		while (s->len_str + i < s->width)
		{
			if (ft_put_wchar_to_buffer(s, ' ', 0) == PRINTF_ERROR)
				return (PRINTF_ERROR);
			i++;
		}
	}
	return (0);
}

int			ft_printf_str(t_printf *s)
{
	int i;

	s->len_str = ft_strlen((void *)s->str);
	if (s->precision > -1)
		s->len_str = ft_min(s->len_str, s->precision);
	if (ft_width(s) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	i = 0;
	while (i++ < s->nb_zeroes)
		if (ft_put_wchar_to_buffer(s, '0', 0) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	i = 0;
	while (i < s->len_str)
		if (ft_put_wchar_to_buffer(s, s->str[i++], 0) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	if (ft_flag_minus(s) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	return (0);
}

int			ft_printf_wstr(t_printf *s)
{
	int i;

	s->len_str = 0;
	i = 0;
	while (s->wstr[i] != 0 && (s->precision <= -1 ? 1 :
	s->len_str + ft_size_wchar(s->wstr[i]) <= s->precision))
		s->len_str += ft_size_wchar(s->wstr[i++]);
	if (ft_width(s) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	i = 0;
	while (i++ < s->nb_zeroes)
		if (ft_put_wchar_to_buffer(s, '0', 0) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	i = 0;
	while (s->wstr[i] != 0 && (s->precision <= -1 ? 1 :
	ft_size_wchar(s->wstr[i]) <= s->precision))
	{
		if (ft_put_wchar_to_buffer(s, s->wstr[i], 1) == PRINTF_ERROR)
			return (PRINTF_ERROR);
		s->precision -= ft_size_wchar(s->wstr[i++]);
	}
	if (ft_flag_minus(s) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	return (0);
}

int			ft_type_str(t_printf *s)
{
	unsigned char	null_str[7];
	wchar_t			null_wstr[7];

	if (s->type != 's' && s->type != 'S')
		return (0);
	ft_null_str(null_str, null_wstr);
	if (s->type == 'S' || s->size == 1)
	{
		if ((s->wstr = va_arg(s->params, wchar_t *)) == NULL)
			s->wstr = null_wstr;
		if (ft_printf_wstr(s) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	}
	else
	{
		if ((s->str = (unsigned char *)va_arg(s->params, char *)) == NULL)
			s->str = null_str;
		if (ft_printf_str(s) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	}
	return (0);
}
