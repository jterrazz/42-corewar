/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:10:08 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/10 15:51:19 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *result;

	if (s == NULL)
		return (NULL);
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, &s[start], len);
	return (result);
}
