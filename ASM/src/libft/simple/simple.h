/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:39:02 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/26 14:39:03 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_H
# define SIMPLE_H

char					*ft_ullint_to_str(unsigned long long int n,
						unsigned int base, int uppercase);

long long int			ft_str_to_llint(char *s);

unsigned long long int	ft_str_to_ullint(char *s, unsigned int base);

#endif
