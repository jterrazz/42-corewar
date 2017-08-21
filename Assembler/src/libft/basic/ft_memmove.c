/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:31:22 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/15 13:54:31 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	char		*dst;
	const char	*src;
	long long	i;

	dst = destination;
	src = source;
	if (destination < source)
	{
		i = 0;
		while (i < (long long)n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			dst[i] = src[i];
			i--;
		}
	}
	return (destination);
}
