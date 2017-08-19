/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:26:28 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/10 15:52:16 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_to_remove(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int i_first;
	int i_last;
	int len_result;

	if (s == NULL)
		return (NULL);
	i_first = 0;
	while (ft_to_remove(s[i_first]))
		i_first++;
	i_last = ft_strlen(s) - 1;
	while (i_last >= 0 && ft_to_remove(s[i_last]))
		i_last--;
	len_result = i_last - i_first + 1;
	if (len_result < 0)
		len_result = 0;
	return (ft_strsub(s, i_first, len_result));
}
