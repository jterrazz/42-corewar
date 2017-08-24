/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:08:46 by plogan            #+#    #+#             */
/*   Updated: 2017/08/24 19:16:28 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_flags f;

	if (argc == 1)
		ft_usage();
	init_flags(&f, argc, argv);
	parse_args(&f, argc, argv);
	recalculate_players_nb(&f);
	if (f.nb_players > 0)
	{
		init_arena(&f);
		init_processes(&f);
		print_all_players(&f);
		launch_processes(&f);
		print_last_player_alive(&f);
	}
	else
		ft_error(&f, 15);
	return (0);
}
