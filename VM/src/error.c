#include "vm.h"

// use My ft_putstr_fd !

void ft_usage(void)
{
	ft_putstr_fd("Usage: ./corewar [-dump N] [-v N] <champion1.cor> <...>\n", 2); // Ft usage on error ?
	exit(1);
}

void ft_error(t_flags *f, int n)
{
	free_processes(f);
	if (!n)
		ft_putstr_fd("There are too many players !\n", 2);
	else if (n == 1)
		ft_putstr_fd("Error: Size of player is too big\n", 2);
	else if (n == 2)
		ft_putstr_fd("Error: Couldn't open file\n", 2);
	else if (n == 3)
		ft_putstr_fd("Error: Couldn't read file\n", 2);
	else if (n == 4)
		ft_putstr_fd("Error: Couldn't close file\n", 2);
	else if (n == 5)
		ft_putstr_fd("Error: Player numbers can't be the same\n", 2);
	else if (n == 6)
		ft_putstr_fd("Error: -n flag must be followed by a number and the player file\n", 2);
	else if (n == 7)
		ft_putstr_fd("Error: -n flag must be followed by a number\n", 2);
	else if (n == 8)
		ft_putstr_fd("Error: COREWAR_EXEC_MAGIC is bad\n", 2);
	else if (n == 9)
		ft_putstr_fd("Error: File is not .cor\n", 2);
	else if (n == 10)
		ft_putstr_fd("Error: Number is not an INT value\n", 2);
	else if (n == 11)
		ft_putstr_fd("Error: -dump must be followed by a number\n", 2);
	else if (n == 12)
		ft_putstr_fd("Error: The player number must be between 1 and INT_MAX\n", 2); // really int max ?
	else if (n == 13)
		ft_putstr_fd("Error: -n N must be followed by a player\n", 2);
	else if (n == 13)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	exit(1);
}
