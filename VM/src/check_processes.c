#include "vm.h"

static void	check_processes_lives(t_flags *f)
{
	t_process *process;

	process = f->first_process;
	while (process)
	{
		if (process->nb_lives == 0)
			process->is_alive = 0;
		process->nb_lives = 0;
		process = process->next;
	}
}

void check_end_of_cycles(t_flags *f, int *run)
{
	if (f->nb_lives_in_round == 0 || f->nb_cycles_to_die - CYCLE_DELTA <= 0)
		*run = 0;
	if (f->nb_lives_in_round >= NBR_LIVE || f->nb_checks_wo_decrement >= MAX_CHECKS)
	{
		f->nb_cycles_to_die -= CYCLE_DELTA;
		f->nb_checks_wo_decrement = 0;
		if (f->print_cycles)
			ft_printf("Cycle to die is now %d\n", f->nb_cycles_to_die);
	}
	f->nb_checks_wo_decrement++;
	check_processes_lives(f);
	f->nb_lives_in_round = 0;
	f->nb_cycles_done = 1;
	f->nb_cycles_done_since_start++;
}
