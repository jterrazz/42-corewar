/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:31:24 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/21 14:27:58 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char **str)
{
	long	res;
	int		is_neg;

	res = 0;
	is_neg = 0;
	while (**str == '\t' || **str == ' ' || **str == '\f'
			|| **str == '\n' || **str == '\r' || **str == '\v')
		(*str)++;
	if (**str == '-')
		is_neg = 1;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str && **str >= '0' && **str <= '9')
	{
		res *= 10;
		res += **str - '0';
		(*str)++;
	}
	if (is_neg)
		res *= -1;
	return ((int)res);
}

int		ft_atoi_int(char **str, int *is_int)
{
	long	res;
	int		is_neg;

	res = 0;
	is_neg = 0;
	*is_int = 1;
	while (**str == '\t' || **str == ' ' || **str == '\f'
			|| **str == '\n' || **str == '\r' || **str == '\v')
		(*str)++;
	if (**str == '-')
		is_neg = 1;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str && **str >= '0' && **str <= '9')
	{
		res *= 10;
		res += **str - '0';
		(*str)++;
	}
	if (is_neg)
		res *= -1;
	if (res < -2147483648 || res > 2147483647)
		*is_int = 0;
	return ((int)res);
}

long	ft_atoi_long(const char *str)
{
	long	i;
	long	res;
	long	is_neg;

	i = 0;
	res = 0;
	is_neg = 0;
	while (*(str + i) == '\t' || *(str + i) == ' ' || *(str + i) == '\f'
			|| *(str + i) == '\n' || *(str + i) == '\r' || *(str + i) == '\v')
		i++;
	if (*(str + i) == '-')
		is_neg = 1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		res *= 10;
		res += *(str + i) - '0';
		i++;
	}
	if (is_neg)
		res *= -1;
	return (res);
}
