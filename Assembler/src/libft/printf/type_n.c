/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:27:48 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 20:19:14 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_type_n(t_printf *s)
{
	char		*pchar;
	short int	*pshort;
	int			*pint;

	if (s->type != 'n')
		return ;
	if (s->size == -2)
	{
		pchar = va_arg(s->params, char *);
		*pchar = s->nb_chars_written;
	}
	else if (s->size == -1)
	{
		pshort = va_arg(s->params, short int *);
		*pshort = s->nb_chars_written;
	}
	else if (s->size == 0)
	{
		pint = va_arg(s->params, int *);
		*pint = s->nb_chars_written;
	}
	else
		ft_type_n_2(s);
}

void	ft_type_n_2(t_printf *s)
{
	long int		*pl;
	long long int	*pll;
	intmax_t		*pintmax;
	size_t			*psize;

	if (s->size == 1)
	{
		pl = va_arg(s->params, long int *);
		*pl = s->nb_chars_written;
	}
	else if (s->size == 2)
	{
		pll = va_arg(s->params, long long int *);
		*pll = s->nb_chars_written;
	}
	else if (s->size == 3)
	{
		pintmax = va_arg(s->params, intmax_t *);
		*pintmax = s->nb_chars_written;
	}
	else if (s->size == 4)
	{
		psize = va_arg(s->params, size_t *);
		*psize = s->nb_chars_written;
	}
}
