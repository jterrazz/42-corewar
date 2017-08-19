/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:37:52 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/25 18:01:54 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *s)
{
	long long	result;
	int			i;
	int			sign;

	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(s[i]))
	{
		result *= 10;
		result += s[i] - 48;
		if (result < 0)
			return (sign == 1 ? -1 : 0);
		i++;
	}
	result *= sign;
	return (result);
}
