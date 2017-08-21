/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:38:41 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/13 20:28:12 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int len_dst;
	unsigned int len_src;
	unsigned int i;

	len_dst = 0;
	while (len_dst < size && dst[len_dst] != 0)
		len_dst++;
	len_src = ft_strlen(src);
	if (len_dst != size)
	{
		i = 0;
		while (i < len_src && len_dst + i < size - 1)
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = 0;
	}
	return (len_dst + len_src);
}
