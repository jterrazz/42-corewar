/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:13:52 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/13 14:02:43 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;
	unsigned int		i;

	dst = destination;
	src = source;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (dst[i] == c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
