#include "vm.h"

//create a copy of the process a end or process list

static int	get_next_nb_process(t_flags *f, int last_nb_process)
{
	t_process *process;
	int i;

	i = last_nb_process;
	process = f->first_process;
	while (process)
	{
		if (process->nb_process == i)
		{
			i++;
			process = f->first_process;
		}
		else
			process = process->next;
	}
	return (i);
}

void copy_process(t_process *dest, t_process *src)
{
	int i;

	i = 0;
	dest->is_head = src->is_head;
	dest->i = src->i;
	dest->nb_process = src->nb_process;
	dest->nb_lives = src->nb_lives;
	dest->player = src->player;
	dest->is_alive = src->is_alive;
	dest->is_running = 0;
	dest->is_waiting_for_n_cycles = 0;
	dest->carry = src->carry;
	while (i < REG_NUMBER)
	{
		dest->reg[i] = src->reg[i];
		i++;
	}
	dest->next = NULL;
}

void make_fork(t_flags *f, t_process *process, int is_long)
{
	t_process	*new_process;
	int			i_to_add;

	if (!(new_process = (t_process *)malloc(sizeof(t_process))))
		ft_error(f, 12); // TODO Deal with malloc error
	copy_process(new_process, process);
	new_process->nb_process = get_next_nb_process(f, new_process->player->last_nb_process);
	new_process->player->last_nb_process = new_process->nb_process;
	f->first_process->is_head = 0;
	new_process->is_head = 1;
	new_process->next = f->first_process;
	f->first_process = new_process;
	i_to_add = get_dir(f, MODULO_MEMORY(process->i + 1), 2);
	if (!is_long)
		i_to_add = MODULO_IDX(i_to_add);
	if (f->print_operations)
		ft_printf(" %d (%d)", i_to_add, new_process->i + i_to_add);
	move_index(f, process, 3, 1);
	move_index(f, new_process, i_to_add, 0); // test if its pushed to the end or list of processes with 3 processes (2 fork and something else)

}

void op_fork(t_flags *f, t_process *process)
{
	make_fork(f, process, 0);
}
