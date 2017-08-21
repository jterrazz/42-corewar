/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ullint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:59:25 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 20:17:54 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_flag_sharp(t_printf *s)
{
	if (s->flag_sharp && (s->ullint != 0 || s->type == 'p'))
	{
		if (s->base == 8)
		{
			s->prefix[0] = '0';
			s->len_prefix = 1;
		}
		else if (s->base == 16)
		{
			s->prefix[0] = '0';
			s->prefix[1] = (s->uppercase ? 'X' : 'x');
			s->len_prefix = 2;
		}
	}
}

static int	ft_width(t_printf *s)
{
	int i;

	if (!s->flag_minus)
	{
		if (s->flag_zero && s->precision <= -1)
			s->nb_zeroes =
			ft_max(s->width - (s->len_prefix + s->len_number), 0);
		else
		{
			i = 0;
			while (s->len_prefix + s->nb_zeroes + s->len_number + i < s->width)
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
		while (s->len_prefix + s->nb_zeroes + s->len_number + i < s->width)
		{
			if (ft_put_wchar_to_buffer(s, ' ', 0) == PRINTF_ERROR)
				return (PRINTF_ERROR);
			i++;
		}
	}
	return (0);
}

int			ft_printf_ullint(t_printf *s)
{
	unsigned char	*number;
	int				i;

	ft_flag_sharp(s);
	if ((number = (unsigned char *)ft_ullint_to_str(s->ullint,
	s->base, s->uppercase)) == NULL)
		return (PRINTF_ERROR);
	s->len_number = ft_strlen((void *)number);
	if (s->precision == 0 && s->ullint == 0)
		if ((s->type != 'o' && s->type != 'O') || !s->flag_sharp)
			s->len_number = 0;
	s->nb_zeroes = ft_max(s->precision - s->len_number, 0);
	if (ft_width(s) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	i = 0;
	while (i < s->len_prefix)
		if (ft_put_wchar_to_buffer(s, s->prefix[i++], 0) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	return (ft_printf_ullint_2(s, number));
}

int			ft_printf_ullint_2(t_printf *s, unsigned char *number)
{
	int i;

	i = 0;
	while (i++ < s->nb_zeroes)
		if (ft_put_wchar_to_buffer(s, '0', 0) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	i = 0;
	while (i < s->len_number)
		if (ft_put_wchar_to_buffer(s, number[i++], 0) == PRINTF_ERROR)
			return (PRINTF_ERROR);
	if (ft_flag_minus(s) == PRINTF_ERROR)
		return (PRINTF_ERROR);
	free(number);
	return (0);
}
