#include "vm.h"
// LDI and LLDI is probably false
void make_ldi(t_flags *f, t_process *process, int is_long)
{
	int ocp;
	int index;
	int adress;
	int adress2;
	int err;
	int value;
	int reg;

	err = 0;
	ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
	index = MODULO_MEMORY(process->i + 2);
	adress = get_value_for_VAR_2B(f, process, &index, (ocp >> 6 & 0b11), &err);
	if (err)
		return ; // TODO move_index
	print_value(f, adress, (ocp >> 6 & 0b11), 0);
	adress2 = get_value_for_VAR_2B(f, process, &index, (ocp >> 4 & 0b11), &err);
	if (err)
		return ; // TODO move_index
	print_value(f, adress2, (ocp >> 4 & 0b11), 0);
	adress += adress2;
	if ((reg = get_reg_id(f, index)) == -1)
		return ; // TODO move_index
	print_value(f, reg, REG_CODE, 1);
	if (!is_long)
		adress = MODULO_IDX(adress);
	value = get_dir(f, MODULO_MEMORY(process->i + adress), 4);
	// TODO value = TAILLE DU REGISTRE ???
	if (f->print_operations)
		ft_printf("\n       | -> load from %d + %d = %d (with pc and mod %d)", adress - adress2, adress2, adress, process->i + adress);
	process->reg[reg] = value;
	if (is_long)
		process->carry = !value;
} // check carry ?

void op_ldi(t_flags *f, t_process *process)
{
	make_ldi(f, process, 0);
	move_index(f, process, get_next_index(f, process), 1);
}
