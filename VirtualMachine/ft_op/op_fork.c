/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:50:02 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:50:46 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_next_nb_process(t_flags *f, int last_nb_process)
{
	t_process	*process;
	int			i;

	i = last_nb_process;
	process = f->first_process;
	while (process)
	{
		if (process->nb_process == i)
		{
			i++;
			if (i == last_nb_process)
				ft_error(f, 17);
			process = f->first_process;
		}
		else
			process = process->next;
	}
	return (i);
}

static void	copy_process(t_process *dest, t_process *src)
{
	int i;

	i = 0;
	dest->is_head = src->is_head;
	dest->i = src->i;
	dest->nb_process = src->nb_process;
	dest->nb_lives = src->nb_lives;
	dest->player = src->player;
	dest->is_alive = 1;
	dest->is_running = 0;
	dest->is_waiting_for_n_cycles = 0;
	dest->carry = src->carry;
	while (i < REG_NUMBER)
	{
		dest->reg[i] = src->reg[i];
		i++;
	}
	dest->next = NULL;
}

void		make_fork(t_flags *f, t_process *process, int is_long)
{
	t_process	*new_process;
	int			i_to_add;

	if (!(new_process = (t_process *)malloc(sizeof(t_process))))
		ft_error(f, 14);
	copy_process(new_process, process);
	new_process->nb_process = get_next_nb_process(f,
			new_process->player->last_nb_process);
	new_process->player->last_nb_process = new_process->nb_process;
	f->first_process->is_head = 0;
	process->is_head = 0;
	new_process->is_head = 1;
	new_process->next = f->first_process;
	f->first_process = new_process;
	i_to_add = get_dir(f, MODULO_MEMORY(process->i + 1), 2);
	if (f->print_operations)
		ft_printf(" %d ", i_to_add);
	if (!is_long)
		i_to_add = MODULO_IDX(i_to_add);
	if (f->print_operations)
		ft_printf("(%d)\n", new_process->i + i_to_add);
	move_index(f, process, 3, 1);
	move_index(f, new_process, i_to_add, 0);
}

void		op_fork(t_flags *f, t_process *process)
{
	make_fork(f, process, 0);
}
