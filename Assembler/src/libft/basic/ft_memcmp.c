/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:47:54 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/13 16:05:17 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *address1, const void *address2, size_t n)
{
	const unsigned char	*bytes1;
	const unsigned char	*bytes2;
	unsigned int		i;

	bytes1 = address1;
	bytes2 = address2;
	i = 0;
	while (i < n)
	{
		if (bytes1[i] != bytes2[i])
			return ((int)bytes1[i] - (int)bytes2[i]);
		i++;
	}
	return (0);
}
