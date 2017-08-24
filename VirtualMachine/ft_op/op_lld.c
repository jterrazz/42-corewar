/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:50:57 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:51:14 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	op_lld_next(t_flags *f, t_process *process, int reg_nb, int value)
{
	if (is_reg(reg_nb))
	{
		process->reg[reg_nb] = value;
		process->carry = !value;
	}
	if (f->print_operations)
		write(1, "\n", 1);
}

void		op_lld(t_flags *f, t_process *process)
{
	int	ocp;
	int	value;
	int	reg_index;
	int	reg_nb;

	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	if ((ocp >> 6 & 0b11) == DIR_CODE)
	{
		value = get_dir(f, MODULO_MEMORY(process->i + 2), 4);
		reg_index = 6;
	}
	else if ((ocp >> 6 & 0b11) == IND_CODE)
	{
		reg_index = 4;
		value = get_ind(f, process, MODULO_MEMORY(process->i + 2), 0);
	}
	else
		return ;
	reg_nb = get_reg_id(f, process->i + reg_index);
	print_value(f, value, (ocp >> 6 & 0b11), 0);
	print_value(f, reg_nb, REG_CODE, 1);
	op_lld_next(f, process, reg_nb, value);
	move_index(f, process, reg_index + 1, 1);
}
