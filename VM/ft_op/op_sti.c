#include "vm.h"

static void make_sti(t_flags *f, t_process *process)
{
	int ocp;
	int value_to_copy;
	int dest;
	int dest2;
	int index;
	int err;

	err = 0;
	index = MODULO_MEMORY(process->i + 2);
	if (f->print_operations)
		ft_printf(" r%d", f->arena[index].value);
	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	value_to_copy = get_value_for_VAR_2B(f, process, &index, ((ocp >> 6) & 0b11), &err);
	if (err)
		return ;
	dest = get_value_for_VAR_2B(f, process, &index, ((ocp >> 4) & 0b11), &err);
	if (err)
		return ;
	print_value(f, dest, ((ocp >> 4) & 0b11), 0);
	dest2 = get_value_for_VAR_2B(f, process, &index, ((ocp >> 2) & 0b11), &err);
	if (err)
		return ;
	print_value(f, dest2, ((ocp >> 2) & 0b11), 0);
	if (f->print_operations)
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod ?)", dest, dest2, dest + dest2);
	dest += dest2;
	f->arena[MODULO_MEMORY(process->i + MODULO_IDX(dest)) + 0].value = (value_to_copy >> 24) & 0xFF; // TODO !!!!!!!!!!!!!!!!!!! cest pas normal
	f->arena[MODULO_MEMORY(process->i + MODULO_IDX(dest)) + 1].value = (value_to_copy >> 16) & 0xFF;
	f->arena[MODULO_MEMORY(process->i + MODULO_IDX(dest)) + 2].value = (value_to_copy >> 8) & 0xFF;
	f->arena[MODULO_MEMORY(process->i + MODULO_IDX(dest)) + 3].value = value_to_copy & 0xFF;
}

void op_sti(t_flags *f, t_process *process)
{
	make_sti(f, process);
	move_index(f, process, get_next_index(f, process), 1);
}
