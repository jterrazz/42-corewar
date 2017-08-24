/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:28:34 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/26 22:13:09 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_type_uint(t_printf *s)
{
	s->uppercase = 0;
	if (s->type == 'u' || s->type == 'U')
		s->base = 10;
	else if (s->type == 'o' || s->type == 'O')
	{
		if (s->flag_sharp)
			s->precision--;
		s->base = 8;
	}
	else if (s->type == 'x' || s->type == 'X')
	{
		s->base = 16;
		if (s->type == 'X')
			s->uppercase = 1;
	}
	else if (s->type == 'p')
	{
		s->flag_sharp = 1;
		s->base = 16;
	}
	else if (s->type == 'b')
		s->base = 2;
	else
		return (0);
	return (ft_type_uint_2(s));
}

int	ft_type_uint_2(t_printf *s)
{
	if (s->type == 'U' || s->type == 'O')
		s->ullint = va_arg(s->params, unsigned long int);
	else if (s->type == 'p')
		s->ullint = (unsigned long long int)va_arg(s->params, void *);
	else if (s->size == -2)
		s->ullint = (unsigned char)va_arg(s->params, unsigned int);
	else if (s->size == -1)
		s->ullint = (unsigned short int)va_arg(s->params, unsigned int);
	else if (s->size == 0)
		s->ullint = va_arg(s->params, unsigned int);
	else if (s->size == 1)
		s->ullint = va_arg(s->params, unsigned long int);
	else if (s->size == 2)
		s->ullint = va_arg(s->params, unsigned long long int);
	else if (s->size == 3)
		s->ullint = va_arg(s->params, uintmax_t);
	else if (s->size == 4)
		s->ullint = va_arg(s->params, size_t);
	return (ft_printf_ullint(s));
}
