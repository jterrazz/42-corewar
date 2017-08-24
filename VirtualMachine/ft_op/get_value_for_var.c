/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_for_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:36:57 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:42:49 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_dir_and_increment(t_flags *f, int *index, int increment)
{
	int ret;

	ret = get_dir(f, *index, increment);
	*index = *index + increment;
	return (ret);
}

static int	get_ind_and_increment(t_flags *f, t_process *process, int *index
	, int increment)
{
	int ret;

	ret = get_ind(f, process, MODULO_MEMORY(*index), 1);
	*index = *index + increment;
	return (ret);
}

int			get_value_var_4b(t_flags *f, t_process *process,
		int *index, char type)
{
	int ret;

	f->op_error = 0;
	ret = 0;
	*index = MODULO_MEMORY(*index);
	if (type == REG_CODE)
	{
		ret = get_reg_id(f, *index);
		if (ret == -1)
		{
			f->op_error = 1;
			return (0);
		}
		ret = process->reg[ret];
		*index = *index + 1;
	}
	else if (type == DIR_CODE)
		ret = get_dir_and_increment(f, index, 4);
	else if (type == IND_CODE)
		ret = get_ind_and_increment(f, process, index, 2);
	else
		f->op_error = 1;
	*index = MODULO_MEMORY(*index);
	return (ret);
}

int			get_value_var_2b(t_flags *f, t_process *process,
		int *index, char type)
{
	int ret;

	f->op_error = 0;
	ret = 0;
	*index = MODULO_MEMORY(*index);
	if (type == REG_CODE)
	{
		ret = get_reg_id(f, *index);
		if (ret == -1)
		{
			f->op_error = 1;
			return (0);
		}
		ret = process->reg[ret];
		*index = *index + 1;
	}
	else if (type == DIR_CODE)
		ret = get_dir_and_increment(f, index, 2);
	else if (type == IND_CODE)
		ret = get_ind_and_increment(f, process, index, 2);
	else
		f->op_error = 1;
	*index = MODULO_MEMORY(*index);
	return (ret);
}
