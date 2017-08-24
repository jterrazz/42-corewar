/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:58:36 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 14:59:25 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_next_player_number(t_flags *f)
{
	int i;
	int nb_min;

	i = 0;
	nb_min = 1;
	while (i < f->nb_players)
	{
		if (f->players[i].nb == nb_min)
		{
			i = 0;
			nb_min++;
		}
		else
			i++;
	}
	return (nb_min);
}

void	recalculate_players_nb(t_flags *f)
{
	int i;

	i = 0;
	while (i < f->nb_players)
	{
		if (!f->players[i].nb_was_defined)
		{
			f->players[i].nb = get_next_player_number(f);
			f->players[i].nb_was_defined = 1;
		}
		i++;
	}
}

int		check_player_nb(t_flags *f, int nb)
{
	int i;

	i = 0;
	while (i < f->nb_players)
	{
		if (f->players[i].nb == nb)
		{
			if (f->players[i].nb_was_defined)
				return (0);
		}
		i++;
	}
	return (1);
}

void	check_exec_magic(t_flags *f, int i)
{
	int		nb;
	char	*p;

	p = f->players[i].data;
	nb = ((MASK(p[0]) << 24) | (MASK(p[1]) << 16) |
			(MASK(p[2]) << 8) | MASK(p[3]));
	if (nb != COREWAR_EXEC_MAGIC)
		ft_error(f, 8);
}

void	check_file_name(t_flags *f, char *str)
{
	int len;

	len = ft_strlen(str);
	if (len < 4)
		ft_error(f, 9);
	str += len - 4;
	if (ft_strcmp(str, ".cor"))
		ft_error(f, 9);
}
