/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:53:23 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:54:47 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		print_op_sti(t_flags *f, t_process *process, int dest,
		int dest2)
{
	if (f->print_operations)
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
		dest, dest2, dest + dest2, process->i + MODULO_IDX(dest + dest2));
}

static void		make_sti(t_flags *f, t_process *process, int ocp, int index)
{
	int value;
	int dest;
	int dest2;

	if (f->print_operations)
		ft_printf(" r%d", f->arena[index].value);
	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	value = get_value_var_2b(f, process, &index, ((ocp >> 6) & 0b11));
	if (f->op_error)
		return ;
	dest = get_value_var_2b(f, process, &index, ((ocp >> 4) & 0b11));
	if (f->op_error)
		return ;
	print_value(f, dest, ((ocp >> 4) & 0b11), 0);
	dest2 = get_value_var_2b(f, process, &index, ((ocp >> 2) & 0b11));
	if (f->op_error)
		return ;
	print_value(f, dest2, ((ocp >> 2) & 0b11), 0);
	print_op_sti(f, process, dest, dest2);
	dest = MODULO_IDX(dest + dest2);
	f->arena[MODULO_MEMORY(process->i + dest + 0)].value = (value >> 24) & 0xFF;
	f->arena[MODULO_MEMORY(process->i + dest + 1)].value = (value >> 16) & 0xFF;
	f->arena[MODULO_MEMORY(process->i + dest + 2)].value = (value >> 8) & 0xFF;
	f->arena[MODULO_MEMORY(process->i + dest + 3)].value = value & 0xFF;
}

void			op_sti(t_flags *f, t_process *process)
{
	make_sti(f, process, 0, MODULO_MEMORY(process->i + 2));
	move_index(f, process, process->nb_jump_if_fail, 1);
}
