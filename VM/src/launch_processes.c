#include "vm.h"

static void check_start_cycle(t_flags *f, int *run)
{
	if (f->will_dump && f->nb_cycles_done_since_start == f->dump_value)
		print_arena(f);
	if (f->nb_cycles_done == f->nb_cycles_to_die)
		check_end_of_cycles(f, run);
	else
	{
		f->nb_cycles_done++;
		f->nb_cycles_done_since_start++;
	}
	if (f->print_cycles)
		ft_printf("It is now cycle %d\n", f->nb_cycles_done_since_start);
}

static void checks_operations(t_flags *f, t_process *process)
{
	if (!process->is_running)
		start_op(f, process);
	else if (process->is_running && process->is_waiting_for_n_cycles <= 1)
		make_op(f, process);
	else if (process->is_running)
		process->is_waiting_for_n_cycles--;
}

// TODO CHECK if no process number available anymore

static void remove_process(t_flags *f, t_process *to_remove)
{
	t_process *temp;

	if (to_remove->nb_process == f->first_process->nb_process)
	{
		f->first_process = to_remove->next;
		f->first_process->is_head = 1;
		free(to_remove);
		return ;
	}
	temp = f->first_process;
	if (!temp->next)
		return ;
	while (temp->next && to_remove->nb_process != temp->next->nb_process)
		temp = temp->next;
	if (temp && to_remove->nb_process == temp->next->nb_process)
	{
		temp->next = to_remove->next;
		free(to_remove);
	}
}

void launch_processes(t_flags *f)
{
	int			run;
	t_process	*process;
	t_process	*temp;

	run = 1;
	process = f->first_process;
	while (run && process)
	{
		if (run && process->is_head)
			check_start_cycle(f, &run);
		if (run && process->is_alive)
			checks_operations(f, process);
		temp = process;
		process = process->next;
		if (!temp->is_alive)
			remove_process(f, temp);
		if (!process)
			process = f->first_process;
	}
	free_processes(f);
}
