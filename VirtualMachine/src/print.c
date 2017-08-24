/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:12:29 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 15:12:57 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_all_players(t_flags *f)
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < f->nb_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			f->players[i].nb, f->players[i].weight, f->players[i].name,
			f->players[i].comment);
		i++;
	}
}

void	print_last_player_alive(t_flags *f)
{
	if (!f->last_player_alive)
		return ;
	ft_printf("Contestant %d, \"%s\", has won !\n", f->last_player_alive->nb,
		f->last_player_alive->name);
}

void	print_arena(t_flags *f)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", f->arena[i].value & 0xFF);
		if (i % 64 == 63)
			ft_printf("\n");
		i++;
	}
}
