/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:24:54 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 20:56:22 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_llint(t_printf *s)
{
	s->base = 10;
	s->uppercase = 0;
	if (s->llint >= 0)
	{
		if (s->flag_plus)
		{
			s->prefix[0] = '+';
			s->len_prefix = 1;
		}
		else if (s->flag_space)
		{
			s->prefix[0] = ' ';
			s->len_prefix = 1;
		}
		s->ullint = s->llint;
	}
	else
	{
		s->prefix[0] = '-';
		s->len_prefix = 1;
		s->ullint = -s->llint;
	}
	return (ft_printf_ullint(s));
}

int	ft_type_int(t_printf *s)
{
	if (s->type != 'd' && s->type != 'D' && s->type != 'i')
		return (0);
	if (s->type == 'D')
		s->llint = va_arg(s->params, long int);
	else if (s->size == -2)
		s->llint = (char)va_arg(s->params, int);
	else if (s->size == -1)
		s->llint = (short int)va_arg(s->params, int);
	else if (s->size == 0)
		s->llint = va_arg(s->params, int);
	else if (s->size == 1)
		s->llint = va_arg(s->params, long int);
	else if (s->size == 2)
		s->llint = va_arg(s->params, long long int);
	else if (s->size == 3)
		s->llint = va_arg(s->params, intmax_t);
	else if (s->size == 4)
		s->llint = va_arg(s->params, size_t);
	return (ft_printf_llint(s));
}
