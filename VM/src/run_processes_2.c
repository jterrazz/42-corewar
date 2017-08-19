#include "vm.h"

int		get_byte_size_VAR(char var, int param_size)
{
	if (var == DIR_CODE)
		return ((param_size == 1 ? 2 : 4));
	else if (var == IND_CODE)
		return (2);
	else if (var == REG_CODE)
		return (1);
	return (0);
}

int		get_next_index_2(int op_code)
{
	int ret;

	ret = 0;
	if (op_code == 1)
		ret = 4;
	else if (op_code == 9 || op_code == 12 || op_code == 15)
		ret = 2;
	return (ret);
}

int		get_next_index(t_flags *f, t_process *process)
{
	char	ocp;
	char	op_code;
	int		nb_params;
	int		ret;

	ret = 0;
	op_code = f->arena[MODULO_MEMORY(process->i)].value & 0xFF;
	if (!check_op(op_code))
		return (1);
	nb_params = f->op_tab[op_code - 1].nb_params;
	if (f->op_tab[op_code - 1].has_ocp)
	{
		ret++;
		ocp = f->arena[MODULO_MEMORY(process->i + 1)].value;
		ret += (nb_params > 0 ? get_byte_size_VAR(ocp >> 6 & 0b11, f->op_tab[op_code - 1].param_size) : 0);
		ret += (nb_params > 1 ? get_byte_size_VAR(ocp >> 4 & 0b11, f->op_tab[op_code - 1].param_size) : 0);
		ret += (nb_params > 2 ? get_byte_size_VAR(ocp >> 2 & 0b11, f->op_tab[op_code - 1].param_size) : 0);
	}
	else
		ret = get_next_index_2(op_code);
	return (ret + 1);
}
