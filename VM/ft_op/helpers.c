#include "vm.h"

int	is_reg(int i)
{
	if (i < 0 || i >= REG_NUMBER)
		return (0);
	return (1);
}

void print_value(t_flags *f, int value, int type, int print_r)
{
	if (f->print_operations)
	{
		if (print_r && type == REG_CODE)
			ft_printf(" r%d", value + 1);
		else
			ft_printf(" %d", value);
	}
}
