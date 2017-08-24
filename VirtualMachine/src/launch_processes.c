/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:10:10 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 16:24:02 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	check_head_process(t_flags *f, int *run)
{
	f->nb_cycles_done++;
	f->nb_cycles_done_since_start++;
	if (f->print_cycles)
		ft_printf("It is now cycle %d\n", f->nb_cycles_done_since_start);
	if (f->will_dump && f->nb_cycles_done_since_start > f->dump_value)
	{
		print_arena(f);
		*run = 0;
		f->last_player_alive = 0;
	}
}

static void	checks_operations(t_flags *f, t_process *process, t_ft_op *ft_op)
{
	if (!process->is_running)
		start_op(f, process);
	else if (process->is_running && process->is_waiting_for_n_cycles <= 1)
		make_op(f, process, ft_op);
	else if (process->is_running)
		process->is_waiting_for_n_cycles--;
}

void		launch_processes(t_flags *f)
{
	int			run;
	t_process	*process;
	t_process	*temp;
	t_ft_op		ft_op[17];

	init_ft_op_tab(ft_op, &run);
	process = f->first_process;
	f->last_player_alive = f->first_process->player;
	while (run && process)
	{
		if (run && process->is_head)
			check_head_process(f, &run);
		if (run && process->is_alive)
			checks_operations(f, process, ft_op);
		temp = process;
		if (process)
			process = process->next;
		if (!process)
		{
			if (f->nb_cycles_done >= f->nb_cycles_to_die)
				check_end_of_cycles(f, &run);
			process = f->first_process;
		}
	}
	free_processes(f);
}
