#include "vm.h"

static void make_xor(t_flags *f, t_process *process)
{
	int v1;
	int v2;
	int ocp;
	int index;
	int err;
	int dest;

	err = 0;
	index = MODULO_MEMORY(process->i + 2);
	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	v1 = get_value_for_VAR_4B(f, process, &index, (ocp >> 6 & 0b11), &err);
	if (err)
		return ; //TODO AND JUMP
	print_value(f, v1, (ocp >> 6 & 0b11), 0);
	v2 = get_value_for_VAR_4B(f, process, &index, (ocp >> 4 & 0b11), &err);
	if (err)
		return ; //TODO AND JUMP
	print_value(f, v2, (ocp >> 4 & 0b11), 0);
	if ((dest = get_reg_id(f, index)) == -1)
		return ; // TODO JUMP
	print_value(f, dest, REG_CODE, 1);
	process->reg[dest] = v1 | v2;
	process->carry = !process->reg[dest];
}

void op_xor(t_flags *f, t_process *process)
{
	make_xor(f, process);
	move_index(f, process, get_next_index(f, process), 1);
}
