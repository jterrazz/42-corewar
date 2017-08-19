#include "vm.h"

int main(int argc, char **argv)
{
	t_flags f;

	if (argc == 1)
		ft_usage();
	init_flags(&f, argc, argv);
	parse_args(&f, argc, argv);
	recalculate_players_nb(&f);
	init_arena(&f);
	init_processes(&f);
	print_all_players(&f);
	launch_processes(&f);
	print_last_player_alive(&f);
	return (0);
}

// opti lseek
// CARRY MODIFY AFTER EACH OP ?????
// free all var
// check if no players make a live
// make better ruby script
// Check all error msg with commads !
// if no player do nothing ? Check if not segfault
// chec we can print all op in bonus -v 4
