/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:10:31 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/14 18:34:40 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_std_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_std_list *result;

	result = malloc(sizeof(t_std_list));
	if (result == NULL)
		return (NULL);
	if (content == NULL)
	{
		result->content = NULL;
		result->content_size = 0;
	}
	else
	{
		result->content = ft_memalloc(content_size);
		ft_memcpy(result->content, content, content_size);
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}
