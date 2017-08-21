#include "vm.h"

void	op_lfork(t_flags *f, t_process *process)
{
	make_fork(f, process, 1);
}
