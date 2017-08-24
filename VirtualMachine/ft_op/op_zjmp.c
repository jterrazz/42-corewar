/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:53:11 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:53:13 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_zjmp(t_flags *f, t_process *process)
{
	int nb;

	nb = get_dir(f, process->i + 1, 2);
	print_value(f, nb, DIR_CODE, 0);
	if (process->carry == 1)
	{
		if (f->print_operations)
			ft_printf(" OK\n");
		move_index(f, process, MODULO_IDX(nb), 0);
	}
	else
	{
		if (f->print_operations)
			ft_printf(" FAILED\n");
		move_index(f, process, 3, 1);
	}
}
