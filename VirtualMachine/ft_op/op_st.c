/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:54:21 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 18:24:55 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		make_st(t_flags *f, t_process *process, int r1, int r2)
{
	int	ocp;

	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	if ((r1 = get_reg_id(f, process->i + 2)) == -1)
		return ;
	print_value(f, r1, REG_CODE, 1);
	r1 = process->reg[r1];
	if ((ocp >> 4 & 0b11) == REG_CODE)
	{
		if ((r2 = get_reg_id(f, process->i + 3)) == -1)
			return ;
		process->reg[r2] = r1;
		print_value(f, r2 + 1, REG_CODE, 0);
	}
	else if ((ocp >> 4 & 0b11) == IND_CODE)
	{
		r2 = get_dir(f, process->i + 3, 2);
		print_value(f, r2, DIR_CODE, 0);
		r2 = MODULO_IDX(r2);
		f->arena[MODULO_MEMORY((process->i + r2 + 0))].value = r1 >> 24 & 0xFF;
		f->arena[MODULO_MEMORY((process->i + r2 + 1))].value = r1 >> 16 & 0xFF;
		f->arena[MODULO_MEMORY((process->i + r2 + 2))].value = r1 >> 8 & 0xFF;
		f->arena[MODULO_MEMORY((process->i + r2 + 3))].value = r1 & 0xFF;
	}
	f->print_operations ? write(1, "\n", 1) : 0;
}

void			op_st(t_flags *f, t_process *process)
{
	make_st(f, process, 0, 0);
	move_index(f, process, process->nb_jump_if_fail, 1);
}
