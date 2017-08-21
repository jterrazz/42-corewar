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

int		get_value_for_VAR_4B(t_flags *f, t_process *process,
		int *index, char type, int *err)
{
	int ret;

	*err = 0;
	ret = 0;
	*index = MODULO_MEMORY(*index);
	if (type == REG_CODE)
	{
		ret = get_reg_id(f, *index);
		if (ret == -1)
		{
			*err = 1;
			return (0);
		}
		ret = process->reg[ret];
		*index = *index + 1;
	}
	else if (type == DIR_CODE)
	{
		ret = get_dir(f, *index, 4);
		*index = *index + 4;
	}
	else if (type == IND_CODE)
	{
		ret = get_ind(f, process, MODULO_MEMORY(*index), 1);
		*index = *index + 2;
	}
	else
		*err = 1;
	*index = MODULO_MEMORY(*index);
	return (ret);
}

int		get_value_for_VAR_2B(t_flags *f, t_process *process,
		int *index, char type, int *err)
{
	int ret;

	*err = 0;
	ret = 0;
	*index = MODULO_MEMORY(*index);
	if (type == REG_CODE)
	{
		ret = get_reg_id(f, *index);
		if (ret == -1)
		{
			*err = 1;
			return (0);
		}
		ret = process->reg[ret];
		*index = *index + 1;
	}
	else if (type == DIR_CODE)
	{
		ret = get_dir(f, *index, 2);
		*index = *index + 2;
	}
	else if (type == IND_CODE)
	{
		ret = get_ind(f, process, MODULO_MEMORY(*index), 1);
		*index = *index + 2;
	}
	else
		*err = 1;
	*index = MODULO_MEMORY(*index);
	return (ret);
}
