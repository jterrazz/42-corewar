#include "vm.h"

static void (*ft_op[17])(t_flags *f, t_process *process) =  //TODO Cant do static var
{
	0, op_live, op_ld, op_st, op_add, op_sub, op_and, op_or, op_xor, op_zjmp,
	op_ldi, op_sti, op_fork, op_lld, op_lldi, op_lfork, op_aff
};

int move_index(t_flags *f, t_process *process, int nb, int print)
{
	int i;

	i = 0;
	if (print && f->print_moves)
	{
		ft_printf("\nADV %d (0x%04x -> 0x%04x)", nb, process->i, process->i + nb);
		while (i < nb)
		{
			ft_printf(" %02x", f->arena[MODULO_MEMORY(i + process->i)].value & 0xFF);
			i++;
		}
		ft_printf(" ");
	}
	process->i += nb;
	process->i = MODULO_MEMORY(process->i);
	return (0);
}

void start_op(t_flags *f, t_process *process)
{
	if (check_op(f->arena[process->i].value))
	{
		process->is_running = 1;
		process->is_waiting_for_n_cycles = f->op_tab[f->arena[process->i].value - 1].cycles - 1;
	}
	else
		move_index(f, process, 1, 0);
}

void make_op(t_flags *f, t_process *process)
{
	if (check_op(f->arena[MODULO_MEMORY(process->i)].value & 0xFF) && check_op_args(f, process))
	{
		if (f->print_operations)
			ft_printf("P %4d | %s", process->nb_process, f->op_tab[f->arena[MODULO_MEMORY(process->i)].value - 1].name);
		(*(ft_op + (f->arena[MODULO_MEMORY(process->i)].value & 0xFF)))(f, process);
		if (f->print_operations)
			ft_printf("\n");
		// ft_printf(" - carry :%d \n", process->carry);
	}
	else
		move_index(f, process, get_next_index(f, process), 0);
	process->is_running = 0;
}
