/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:47:45 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:47:47 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	op_ld_next(t_flags *f, t_process *process, int reg_nb, int value)
{
	if (f->print_operations)
		write(1, "\n", 1);
	if (is_reg(reg_nb))
	{
		process->reg[reg_nb] = value;
		process->carry = !value;
	}
}

void		op_ld(t_flags *f, t_process *process)
{
	int ocp;
	int value;
	int reg_index;
	int reg_nb;

	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	if ((ocp >> 6 & 0b11) == DIR_CODE)
	{
		value = get_dir(f, MODULO_MEMORY(process->i + 2), 4);
		reg_index = 6;
	}
	else if ((ocp >> 6 & 0b11) == IND_CODE)
	{
		reg_index = 4;
		value = get_ind(f, process, MODULO_MEMORY(process->i + 2), 1);
	}
	else
		return ;
	print_value(f, value, (ocp >> 6 & 0b11), 0);
	reg_nb = get_reg_id(f, process->i + reg_index);
	print_value(f, reg_nb, REG_CODE, 1);
	op_ld_next(f, process, reg_nb, value);
	move_index(f, process, reg_index + 1, 1);
}
