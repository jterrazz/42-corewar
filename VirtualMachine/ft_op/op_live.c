/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:51:34 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:52:15 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_player_id(t_flags *f, int nb)
{
	int i;

	i = 0;
	while (i < f->nb_players)
	{
		if (f->players[i].nb == nb)
			return (i);
		i++;
	}
	return (-1);
}

void		op_live(t_flags *f, t_process *process)
{
	int nb_player;
	int id_player;

	nb_player = get_dir(f, process->i + 1, 4);
	if (f->print_operations)
		ft_printf(" %d\n", nb_player);
	nb_player = ~nb_player + 1;
	id_player = get_player_id(f, nb_player);
	process->nb_lives++;
	f->nb_lives_in_round++;
	if (id_player >= 0)
	{
		f->last_player_alive = &(f->players[id_player]);
		if (f->print_lives)
			ft_printf("Player %d (%s) is said to be alive\n",
					f->players[id_player].nb, f->players[id_player].name);
	}
	move_index(f, process, 5, 1);
}
