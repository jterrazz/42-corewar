/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:04:16 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/10 17:56:45 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_alloc_result(long long *n, int *neg, long long *p10)
{
	int nb_digits;

	if (*n < 0)
	{
		*neg = 1;
		*n *= -1;
	}
	else
		*neg = 0;
	nb_digits = 1;
	*p10 = 1;
	while (*n / *p10 > 9)
	{
		nb_digits++;
		*p10 *= 10;
	}
	return (ft_strnew(*neg + nb_digits));
}

static void	ft_make_result(long long n, char *result, int neg, long long p10)
{
	int i;

	if (neg)
		result[0] = '-';
	i = neg;
	while (p10 > 0)
	{
		result[i] = n / p10 + 48;
		n %= p10;
		p10 /= 10;
		i++;
	}
}

char		*ft_itoa(int n)
{
	long long	copy;
	char		*result;
	int			neg;
	long long	p10;

	copy = n;
	result = ft_alloc_result(&copy, &neg, &p10);
	if (result == NULL)
		return (NULL);
	ft_make_result(copy, result, neg, p10);
	return (result);
}
