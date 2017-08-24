/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:59:48 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:59:54 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_arena_to_null(t_flags *f)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		f->arena[i].value = 0;
		i++;
	}
}

static void	place_player_in_arena(t_flags *f, int player_nb)
{
	int i;
	int j;

	i = f->players[player_nb].index;
	j = 0;
	while (j < CHAMP_MAX_SIZE)
	{
		f->arena[i].value = f->players[player_nb].prog[j] & 0xFF;
		i++;
		j++;
	}
}

void		init_arena(t_flags *f)
{
	int i;

	i = 0;
	init_arena_to_null(f);
	while (i < f->nb_players)
	{
		f->players[i].index = (MEM_SIZE / f->nb_players) * i;
		place_player_in_arena(f, i);
		i++;
	}
}
