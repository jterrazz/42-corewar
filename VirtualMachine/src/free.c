/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:58:27 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:58:28 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	free_processes(t_flags *f)
{
	t_process *process;
	t_process *temp;

	process = f->first_process;
	while (process)
	{
		temp = process;
		process = process->next;
		free(temp);
	}
}
