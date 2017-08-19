/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:24:02 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 19:07:27 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_get_size_modifier(t_printf *s)
{
	const unsigned char *size;

	size = &s->format[s->i_format];
	if (ft_strnequ((void *)size, "hh", 2))
	{
		s->size = -2;
		s->i_format += 2;
	}
	else if (ft_strnequ((void *)size, "ll", 2))
	{
		s->size = 2;
		s->i_format += 2;
	}
	else if (size[0] == 'h')
	{
		s->size = -1;
		s->i_format++;
	}
	else if (size[0] == 'l')
	{
		s->size = 1;
		s->i_format++;
	}
	else
		ft_get_size_modifier_2(s, size);
}

void	ft_get_size_modifier_2(t_printf *s, const unsigned char *size)
{
	if (size[0] == 'j')
	{
		s->size = 3;
		s->i_format++;
	}
	else if (size[0] == 'z')
	{
		s->size = 4;
		s->i_format++;
	}
	else
		s->size = 0;
}
