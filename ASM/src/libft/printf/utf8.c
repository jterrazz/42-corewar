/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:45:52 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 18:35:38 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_byte4(t_printf *s)
{
	if (s->nb_bits > 16)
	{
		s->i_bit = s->nb_bits - 1 - 18;
		s->i_utf8 = 7;
		if (s->nb_bits > 21)
		{
			ft_strcpy(s->utf8, "10000000");
			while (s->i_utf8 >= 2)
				s->utf8[s->i_utf8--] = s->bits[s->i_bit--];
		}
		else
		{
			ft_strcpy(s->utf8, "11110000");
			while (s->i_bit >= 0)
				s->utf8[s->i_utf8--] = s->bits[s->i_bit--];
		}
		s->buffer[s->i_buffer++] = ft_str_to_ullint(s->utf8, 2);
	}
}

static void	ft_byte3(t_printf *s)
{
	if (s->nb_bits > 11)
	{
		s->i_bit = s->nb_bits - 1 - 12;
		s->i_utf8 = 7;
		if (s->nb_bits > 16)
		{
			ft_strcpy(s->utf8, "10000000");
			while (s->i_utf8 >= 2)
				s->utf8[s->i_utf8--] = s->bits[s->i_bit--];
		}
		else
		{
			ft_strcpy(s->utf8, "11100000");
			while (s->i_bit >= 0)
				s->utf8[s->i_utf8--] = s->bits[s->i_bit--];
		}
		s->buffer[s->i_buffer++] = ft_str_to_ullint(s->utf8, 2);
	}
}

static void	ft_byte2(t_printf *s)
{
	if (s->nb_bits > 7)
	{
		s->i_bit = s->nb_bits - 1 - 6;
		s->i_utf8 = 7;
		if (s->nb_bits > 11)
		{
			ft_strcpy(s->utf8, "10000000");
			while (s->i_utf8 >= 2)
				s->utf8[s->i_utf8--] = s->bits[s->i_bit--];
		}
		else
		{
			ft_strcpy(s->utf8, "11000000");
			while (s->i_bit >= 0)
				s->utf8[s->i_utf8--] = s->bits[s->i_bit--];
		}
		s->buffer[s->i_buffer++] = ft_str_to_ullint(s->utf8, 2);
	}
}

static void	ft_byte1(t_printf *s)
{
	s->i_bit = s->nb_bits - 1;
	s->i_utf8 = 7;
	if (s->nb_bits > 7)
	{
		ft_strcpy(s->utf8, "10000000");
		while (s->i_utf8 >= 2)
			s->utf8[s->i_utf8--] = s->bits[s->i_bit--];
	}
	else
	{
		ft_strcpy(s->utf8, "00000000");
		while (s->i_bit >= 0)
			s->utf8[s->i_utf8--] = s->bits[s->i_bit--];
	}
	s->buffer[s->i_buffer++] = ft_str_to_ullint(s->utf8, 2);
}

void		ft_put_utf8_to_buffer(t_printf *s)
{
	ft_byte4(s);
	ft_byte3(s);
	ft_byte2(s);
	ft_byte1(s);
}
