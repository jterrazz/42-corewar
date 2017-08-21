/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:04:04 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/14 14:41:47 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != 0)
	{
		j = 0;
		while (big[i + j] != 0 && little[j] != 0 && big[i + j] == little[j])
			j++;
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
