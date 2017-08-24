/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:54:29 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:54:30 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		make_xor(t_flags *f, t_process *process, int v1, int v2)
{
	int ocp;
	int index;
	int dest;

	f->op_error = 0;
	index = MODULO_MEMORY(process->i + 2);
	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	v1 = get_value_var_4b(f, process, &index, (ocp >> 6 & 0b11));
	if (f->op_error)
		return ;
	print_value(f, v1, (ocp >> 6 & 0b11), 0);
	v2 = get_value_var_4b(f, process, &index, (ocp >> 4 & 0b11));
	if (f->op_error)
		return ;
	print_value(f, v2, (ocp >> 4 & 0b11), 0);
	if ((dest = get_reg_id(f, index)) == -1)
		return ;
	print_value(f, dest, REG_CODE, 1);
	if (f->print_operations)
		write(1, "\n", 1);
	process->reg[dest] = v1 ^ v2;
	process->carry = !process->reg[dest];
}

void			op_xor(t_flags *f, t_process *process)
{
	make_xor(f, process, 0, 0);
	move_index(f, process, process->nb_jump_if_fail, 1);
}
