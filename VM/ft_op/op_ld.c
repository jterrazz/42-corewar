#include "vm.h"

void op_ld(t_flags *f, t_process *process)
{
	int ocp;
	int value;
	int reg_index;
	int reg_nb;

	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	if ((ocp >> 6 & 0b11) == DIR_CODE)
	{
		value = get_dir(f, MODULO_MEMORY(process->i + 2), 4);
		reg_index = 6;
	}
	else if ((ocp >> 6 & 0b11) == IND_CODE)
	{
		reg_index = 4;
		value = get_ind(f, process, MODULO_MEMORY(process->i + 2), 1);
	}
	else
		return ; //check no other cases possible
	print_value(f, value, (ocp >> 6 & 0b11), 0);
	reg_nb = get_reg_id(f, process->i + reg_index);
	print_value(f, reg_nb, REG_CODE, 01);
	if (is_reg(reg_nb))
	{
		process->reg[reg_nb] = value;
		process->carry = !value;
	}
	move_index(f, process, reg_index + 1, 1);
}
