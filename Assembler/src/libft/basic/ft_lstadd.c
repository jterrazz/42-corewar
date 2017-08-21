/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:27:09 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/12 20:28:28 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd(t_std_list **alst, t_std_list *new_elem)
{
	if (alst == NULL || new_elem == NULL)
		return ;
	new_elem->next = *alst;
	*alst = new_elem;
}
