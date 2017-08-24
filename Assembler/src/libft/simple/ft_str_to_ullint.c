/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_ullint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:43:32 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 17:43:34 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned int		ft_uint(char c)
{
	if (ft_isdigit(c))
		return (c - 48);
	else if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	else
		return (1000);
}

unsigned long long int	ft_str_to_ullint(char *s, unsigned int base)
{
	unsigned long long int	result;
	int						i;

	if (base > 16)
		return (0);
	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	result = 0;
	while (ft_uint(s[i]) < base)
	{
		result *= base;
		result += ft_uint(s[i]);
		i++;
	}
	return (result);
}
