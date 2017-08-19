#include "vm.h"

void op_lld(t_flags *f, t_process *process)
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
		value = get_ind(f, process, MODULO_MEMORY(process->i + 2), 0);
	}
	else
		return ; // Check no other cases
	reg_nb = get_reg_id(f, process->i + reg_index);
	if (is_reg(reg_nb))
	{
		print_value(f, value, (ocp >> 6 & 0b11), 0);
		print_value(f, reg_nb, REG_CODE, 1);
		process->reg[reg_nb] = value;
		process->carry = !value;
	}
	move_index(f, process, reg_index + 1, 1);
}
