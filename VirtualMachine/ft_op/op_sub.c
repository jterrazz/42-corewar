/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:52:38 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 17:59:19 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_sub(t_flags *f, t_process *process)
{
	int value;

	if (is_reg(get_reg_id(f, process->i + 2))
		&& is_reg(get_reg_id(f, process->i + 3))
		&& is_reg(get_reg_id(f, process->i + 4)))
	{
		value = process->reg[get_reg_id(f, process->i + 2)] -
		process->reg[get_reg_id(f, process->i + 3)];
		process->reg[get_reg_id(f, process->i + 4)] = value;
		print_value(f, get_reg_id(f, process->i + 2), REG_CODE, 1);
		print_value(f, get_reg_id(f, process->i + 3), REG_CODE, 1);
		print_value(f, get_reg_id(f, process->i + 4), REG_CODE, 1);
		process->carry = !value;
	}
	if (f->print_operations)
		write(1, "\n", 1);
	move_index(f, process, 5, 1);
}
