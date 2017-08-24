/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:48:50 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:49:51 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		make_ldi_next(t_flags *f, t_process *process, t_adresses *a,
		int is_long)
{
	int value;

	if (f->print_operations)
		ft_printf("\n       | -> load from %d + %d = %d", a->adress1,
				a->adress2, a->sum);
	if (!is_long)
		a->sum = MODULO_IDX(a->sum);
	value = get_dir(f, MODULO_MEMORY(process->i + a->sum), 4);
	if (f->print_operations)
		ft_printf(" (with pc and mod %d)\n", process->i + a->sum);
	return (value);
}

void	make_ldi(t_flags *f, t_process *process, int is_long, int ocp)
{
	t_adresses	a;
	int			index;
	int			value;
	int			reg;

	f->op_error = 0;
	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	index = MODULO_MEMORY(process->i + 2);
	a.adress1 = get_value_var_2b(f, process, &index, (ocp >> 6 & 0b11));
	if (f->op_error)
		return ;
	print_value(f, a.adress1, (ocp >> 6 & 0b11), 0);
	a.adress2 = get_value_var_2b(f, process, &index, (ocp >> 4 & 0b11));
	if (f->op_error)
		return ;
	print_value(f, a.adress2, (ocp >> 4 & 0b11), 0);
	a.sum = a.adress1 + a.adress2;
	if ((reg = get_reg_id(f, index)) == -1)
		return ;
	print_value(f, reg, REG_CODE, 1);
	value = make_ldi_next(f, process, &a, is_long);
	process->reg[reg] = value;
	if (is_long)
		process->carry = !value;
}

void	op_ldi(t_flags *f, t_process *process)
{
	make_ldi(f, process, 0, 0);
	move_index(f, process, process->nb_jump_if_fail, 1);
}
