#include "vm.h"

void	op_lldi(t_flags *f, t_process *process)
{
	make_ldi(f, process, 1);
	move_index(f, process, get_next_index(f, process), 1);
}
