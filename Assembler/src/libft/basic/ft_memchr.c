/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:40:02 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/13 14:07:16 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *address, int value, size_t n)
{
	const unsigned char	*bytes;
	unsigned int		i;

	bytes = address;
	i = 0;
	while (i < n)
	{
		if (bytes[i] == value)
			return ((void *)&bytes[i]);
		i++;
	}
	return (NULL);
}
