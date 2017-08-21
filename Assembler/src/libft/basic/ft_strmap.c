/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:36:55 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/20 16:34:36 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		result[i] = f(s[i]);
		i++;
	}
	return (result);
}
