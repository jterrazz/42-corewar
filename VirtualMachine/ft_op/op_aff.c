/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:38:18 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:38:35 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		make_aff(t_flags *f, t_process *process)
{
	int				reg_id;
	unsigned char	value;

	reg_id = get_reg_id(f, process->i + 2);
	if (reg_id == -1 ||
			f->arena[MODULO_MEMORY(process->i + 1)].value != 0b01000000)
		return ;
	value = (unsigned char)process->reg[reg_id] % 256;
	if (f->print_aff)
		ft_printf("Aff: %c\n", value);
}

void			op_aff(t_flags *f, t_process *process)
{
	make_aff(f, process);
	move_index(f, process, 3, 1);
}
