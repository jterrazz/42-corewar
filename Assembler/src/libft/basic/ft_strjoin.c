/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:16:55 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/10 15:07:19 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	len_s1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	result = ft_strnew(len_s1 + ft_strlen(s2));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcpy(&result[len_s1], s2);
	return (result);
}
