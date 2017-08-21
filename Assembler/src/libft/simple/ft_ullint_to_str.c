/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullint_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:38:48 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/31 21:09:22 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	ft_digit(unsigned int n, int uppercase)
{
	if (n <= 9)
		return (n + 48);
	if (n == 10)
		return (uppercase ? 'A' : 'a');
	if (n == 11)
		return (uppercase ? 'B' : 'b');
	if (n == 12)
		return (uppercase ? 'C' : 'c');
	if (n == 13)
		return (uppercase ? 'D' : 'd');
	if (n == 14)
		return (uppercase ? 'E' : 'e');
	return (uppercase ? 'F' : 'f');
}

char		*ft_ullint_to_str(unsigned long long int n,
unsigned int base, int uppercase)
{
	char					*result;
	int						i;
	unsigned long long int	power;

	if (base > 16)
		return (NULL);
	i = 1;
	power = 1;
	while (n / power >= base)
	{
		i++;
		power *= base;
	}
	if ((result = ft_strnew(i)) == NULL)
		return (NULL);
	i = 0;
	while (power > 0)
	{
		result[i] = ft_digit(n / power, uppercase);
		n %= power;
		power /= base;
		i++;
	}
	return (result);
}
