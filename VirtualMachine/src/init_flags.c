/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:00:06 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 18:55:00 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_ft_op_tab(t_ft_op *op_tab, int *run)
{
	*run = 1;
	op_tab[0].ft = 0;
	op_tab[1].ft = &op_live;
	op_tab[2].ft = &op_ld;
	op_tab[3].ft = &op_st;
	op_tab[4].ft = &op_add;
	op_tab[5].ft = &op_sub;
	op_tab[6].ft = &op_and;
	op_tab[7].ft = &op_or;
	op_tab[8].ft = &op_xor;
	op_tab[9].ft = &op_zjmp;
	op_tab[10].ft = &op_ldi;
	op_tab[11].ft = &op_sti;
	op_tab[12].ft = &op_fork;
	op_tab[13].ft = &op_lld;
	op_tab[14].ft = &op_lldi;
	op_tab[15].ft = &op_lfork;
	op_tab[16].ft = &op_aff;
}

void		init_flags(t_flags *f, int argc, char **argv)
{
	f->nb_cycles_done = 0;
	f->nb_checks_wo_decrement = 1;
	f->nb_cycles_done_since_start = 0;
	f->nb_cycles_to_die = CYCLE_TO_DIE;
	f->nb_players = 0;
	f->last_player_alive = NULL;
	f->nb_lives_in_round = 0;
	f->will_dump = 0;
	f->dump_value = 0;
	f->argc = argc;
	f->argv = argv;
	f->first_process = NULL;
	f->print_aff = 0;
	f->print_cycles = 0;
	f->print_operations = 0;
	f->print_moves = 0;
	f->print_lives = 0;
	init_op_tab(f);
}
