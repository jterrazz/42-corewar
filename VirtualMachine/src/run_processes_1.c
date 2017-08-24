/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_processes_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:41:27 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 16:21:18 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		move_index(t_flags *f, t_process *process, int nb, int print)
{
	int i;

	i = 0;
	if (print && f->print_moves)
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x)", nb, process->i,
				process->i + nb);
		while (i < nb)
		{
			ft_printf(" %02x",
					f->arena[MODULO_MEMORY(i + process->i)].value & 0xFF);
			i++;
		}
		ft_printf(" \n");
	}
	process->i += nb;
	process->i = MODULO_MEMORY(process->i);
	return (0);
}

void	start_op(t_flags *f, t_process *process)
{
	if (check_op(f->arena[process->i].value))
	{
		process->op_to_do = f->arena[process->i].value & 0xFF;
		process->is_running = 1;
		process->is_waiting_for_n_cycles =
			f->op_tab[f->arena[process->i].value - 1].cycles - 1;
	}
	else
		move_index(f, process, 1, 0);
}

void	make_op(t_flags *f, t_process *process, t_ft_op *ft_op)
{
	process->nb_jump_if_fail = get_next_index(f, process, 1);
	if (check_op(process->op_to_do) && check_op_args(f, process))
	{
		if (f->print_operations && process->op_to_do != 16)
			ft_printf("P %4d | %s", process->nb_process,
					f->op_tab[process->op_to_do - 1].name);
		ft_op[process->op_to_do].ft(f, process);
	}
	else
	{
		move_index(f, process, process->nb_jump_if_fail, 1);
	}
	process->is_running = 0;
}
