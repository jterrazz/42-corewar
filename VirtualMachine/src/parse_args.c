/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:13:03 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 15:13:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_next_arg_if_nb(t_flags *f, int *i, int err_nb)
{
	char	**argv;
	int		j;
	int		nb;
	int		is_int;

	j = 0;
	is_int = 0;
	argv = f->argv;
	if (*i + 1 >= f->argc)
		ft_error(f, 6);
	(*i)++;
	while (argv[*i][j])
	{
		if (!ft_isdigit(argv[*i][j]))
			ft_error(f, err_nb);
		j++;
	}
	nb = ft_atoi_int(argv[*i], &is_int);
	if (!is_int)
		ft_error(f, 10);
	return (nb);
}

void		parse_first_args(t_flags *f, char **argv, int *i, int *nb)
{
	while (*i < f->argc)
	{
		if (!ft_strcmp(argv[*i], "-a"))
			f->print_aff = 1;
		else if (!ft_strcmp(argv[*i], "-dump") || !ft_strcmp(argv[*i], "-d"))
		{
			f->will_dump = 1;
			f->dump_value = get_next_arg_if_nb(f, i, 11);
		}
		else if (!ft_strcmp(argv[*i], "-v"))
		{
			*nb = get_next_arg_if_nb(f, i, 16);
			if (*nb & 0b1)
				f->print_lives = 1;
			if (*nb >> 1 & 0b1)
				f->print_cycles = 1;
			if (*nb >> 2 & 0b1)
				f->print_operations = 1;
			if (*nb >> 4 & 0b1)
				f->print_moves = 1;
		}
		else
			break ;
		(*i)++;
	}
}

void		parse_args(t_flags *f, int argc, char **argv)
{
	int i;
	int nb;

	i = 1;
	parse_first_args(f, argv, &i, &nb);
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			nb = get_next_arg_if_nb(f, &i, 7);
			if (nb < 1)
				ft_error(f, 12);
			i++;
			if (i >= argc)
				ft_error(f, 13);
			init_player(f, argv[i], nb);
		}
		else
			init_player(f, argv[i], -1);
		i++;
		f->nb_players += 1;
	}
}
