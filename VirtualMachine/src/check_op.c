#include "vm.h"

int	check_op(int op)
{
	if (op > 0 && op <= 16)
		return (1);
	return (0);
}

int	check_op_args(t_flags *f, t_process *process)
{
	int op_code;
	int ocp;
	int i;
	int index;

	i = 0;
	op_code = f->arena[process->i].value;
	if (f->op_tab[op_code - 1].has_ocp == 0)
		return (1);
	index = MODULO_MEMORY(process->i + 1);
	ocp = f->arena[index].value;
	index = MODULO_MEMORY(index + 1);
	while (i < f->op_tab[op_code - 1].nb_params)
	{
		if (((ocp >> (6 - i * 2) & 0b11) == DIR_CODE)
			&& (f->op_tab[op_code - 1].params_type[i] & T_DIR) == T_DIR)
			index = MODULO_MEMORY(index + (f->op_tab[op_code - 1].param_size ? 2 : 4));
		else if (((ocp >> (6 - i * 2) & 0b11) == IND_CODE)
			&& (f->op_tab[op_code - 1].params_type[i] & T_IND) == T_IND)
			index = MODULO_MEMORY(index + 2);
		else if (((ocp >> (6 - i * 2) & 0b11) == REG_CODE)
			&& (f->op_tab[op_code - 1].params_type[i] & T_REG) == T_REG)
			{
				if (f->arena[index].value < 1 || f->arena[index].value > REG_NUMBER)
					return (0);
				index = MODULO_MEMORY(index + 1);
			}
		else
			return (0);
		i++;
	}
	return (1);
}
