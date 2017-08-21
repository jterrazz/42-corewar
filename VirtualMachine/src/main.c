#include "vm.h"

int main(int argc, char **argv)
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

// TODO Not sure if we have to check name and comment chars while reading player
// Check leaks with all errors
// Check -v works the same
// LDI and LLDI check again

// Check why players are in exec mode
// Remove warnings in asm
// Clean all files : .o .cor .my .ref ...

// TODO Write our player

// TODO Make better ruby script : delete all + visual tester
