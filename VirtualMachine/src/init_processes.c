/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:10:21 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 15:12:18 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_zero_process(t_flags *f, t_process *new, int i)
{
	new->player = &(f->players[i]);
	new->next = NULL;
	new->is_running = 0;
	new->is_alive = 1;
	new->nb_lives = 0;
	new->nb_process = new->player->nb;
	new->is_waiting_for_n_cycles = 0;
	new->carry = 0;
	new->i = f->players[i].index;
	new->is_head = 0;
	new->player->last_nb_process = new->nb_process;
}

static void	append_process(t_flags *f, int i)
{
	t_process	*new;
	t_process	*temp;
	int			j;

	j = 0;
	if (!(new = (t_process *)malloc(sizeof(t_process))))
		ft_error(f, 14);
	init_zero_process(f, new, i);
	while (j < REG_NUMBER)
	{
		new->reg[j] = 0;
		j++;
	}
	new->reg[0] = ~(f->players[i].nb - 1);
	temp = f->first_process;
	if (!temp)
		f->first_process = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int			get_player_id_for_biggest_nb(t_flags *f, int last_placed,
		int *value_to_place)
{
	int i;
	int index_max;
	int value_max;

	i = 0;
	index_max = -1;
	value_max = -1;
	while (i < f->nb_players)
	{
		if (f->players[i].nb > value_max && (f->players[i].nb <
					*value_to_place || last_placed == -1))
		{
			index_max = i;
			value_max = f->players[i].nb;
		}
		i++;
	}
	*value_to_place = value_max;
	return (index_max);
}

void		init_processes(t_flags *f)
{
	int			i;
	int			to_place;
	int			value_to_place;

	i = 0;
	to_place = -1;
	value_to_place = -1;
	while (i < f->nb_players)
	{
		to_place = get_player_id_for_biggest_nb(f, to_place, &value_to_place);
		append_process(f, to_place);
		i++;
	}
	f->first_process->is_head = 1;
}
