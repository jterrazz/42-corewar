/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:04:34 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/12 18:06:33 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char			*dst;
	const char		*src;
	unsigned int	i;

	dst = destination;
	src = source;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (destination);
}
