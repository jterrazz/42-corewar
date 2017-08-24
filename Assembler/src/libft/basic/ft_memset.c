/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:52:21 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/13 14:03:06 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *address, int value, size_t n)
{
	unsigned char	*bytes;
	unsigned int	i;

	bytes = address;
	i = 0;
	while (i < n)
	{
		bytes[i] = value;
		i++;
	}
	return (address);
}
