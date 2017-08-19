/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:20:54 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/15 13:52:59 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_std_list **alst, void (*del)(void *, size_t))
{
	t_std_list *elem;
	t_std_list *next;

	if (alst == NULL || del == NULL)
		return ;
	elem = *alst;
	while (elem != NULL)
	{
		next = elem->next;
		ft_lstdelone(&elem, del);
		elem = next;
	}
	*alst = NULL;
}
