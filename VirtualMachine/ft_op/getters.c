/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:37:33 by plogan            #+#    #+#             */
/*   Updated: 2017/08/21 15:39:48 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_dir(t_flags *f, int index, int size)
{
	int ret;

	if (size == 2)
	{
		ret = (f->arena[MODULO_MEMORY(index)].value & 0xFF) << 8
			| (f->arena[MODULO_MEMORY(index + 1)].value & 0xFF);
		return ((short)ret);
	}
	else if (size == 4)
	{
		ret = (f->arena[MODULO_MEMORY(index)].value & 0xFF) << 24
			| (f->arena[MODULO_MEMORY(index + 1)].value & 0xFF) << 16
			| (f->arena[MODULO_MEMORY(index + 2)].value & 0xFF) << 8
			| (f->arena[MODULO_MEMORY(index + 3)].value & 0xFF);
		return (ret);
	}
	return (0);
}

int		get_reg_id(t_flags *f, int index)
{
	int ret;

	ret = f->arena[MODULO_MEMORY(index)].value & 0xFF;
	if (ret < 1 || ret > REG_NUMBER)
		return (-1);
	return (ret - 1);
}

int		get_ind(t_flags *f, t_process *process, int index, int use_idx)
{
	int to_go;

	if (use_idx)
		to_go = process->i + MODULO_IDX(get_dir(f, index, 2));
	else
		to_go = process->i + get_dir(f, index, 2);
	to_go = MODULO_MEMORY(to_go);
	return (get_dir(f, to_go, 4));
}
