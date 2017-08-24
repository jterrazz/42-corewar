/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:45:47 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/20 16:35:50 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
