//header

#include "vm.h"

void init_flags(t_flags *f, int argc, char **argv)
{
	f->nb_cycles_done = 0;
	f->nb_checks_wo_decrement = 0;
	f->nb_cycles_done_since_start = 0;
	f->nb_cycles_to_die = CYCLE_TO_DIE;
	f->nb_players = 0;
	f->last_player_alive = NULL;
	f->nb_lives_in_round = 0;
	f->will_dump = 0;
	f->dump_value = 0;
	f->argc = argc;
	f->argv = argv;
	f->first_process = NULL;
	f->print_aff = 0;
	f->print_cycles = 0;
	f->print_operations = 0;
	f->print_moves = 0;
	f->print_lives = 0;
	init_op_tab(f);
}
