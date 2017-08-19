#include "vm.h"

void free_processes(t_flags *f)
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
