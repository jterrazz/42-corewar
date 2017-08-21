/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:10:56 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/12 18:18:00 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (src[i] == 0)
			while (i < n)
				dst[i++] = 0;
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
