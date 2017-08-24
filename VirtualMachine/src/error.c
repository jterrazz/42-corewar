/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:04:58 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 15:08:43 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_usage(void)
{
	ft_putstr_fd("Usage: ./corewar [-dump N] [-v N] [-a]", 2);
	ft_putstr_fd(" <champion1.cor> <...>\n", 2);
	ft_putstr_fd("    -a        : Prints output from \"aff\" (", 2);
	ft_putstr_fd("Default is to hide it)\n", 2);
	ft_putstr_fd("#### TEXT OUTPUT MODE ################", 2);
	ft_putstr_fd("##########################################\n", 2);
	ft_putstr_fd("    -d N      : Dumps memory after N cycles then exits\n", 2);
	ft_putstr_fd("    -v N      : Verbosity levels, can be added ", 2);
	ft_putstr_fd("together to enable several\n", 2);
	ft_putstr_fd("                - 0 : Show only essentials\n", 2);
	ft_putstr_fd("                - 1 : Show lives\n", 2);
	ft_putstr_fd("                - 2 : Show cycles\n", 2);
	ft_putstr_fd("                - 4 : Show operations (Params ", 2);
	ft_putstr_fd("are NOT litteral ...)\n", 2);
	ft_putstr_fd("                - 16 : Show PC movements (Exce", 2);
	ft_putstr_fd("pt for jumps)\n", 2);
	ft_putstr_fd("#############################################", 2);
	ft_putstr_fd("###################################\n", 2);
	exit(1);
}

static int	ft_error_next(int n)
{
	if (n == 10)
		ft_putstr_fd("Error: Number is not an INT value\n", 2);
	else if (n == 11)
		ft_putstr_fd("Error: -dump must be followed by a number\n", 2);
	else if (n == 12)
		ft_putstr_fd("Error: Player number must be between 1 and INT_MAX\n", 2);
	else if (n == 13)
		ft_putstr_fd("Error: -n N must be followed by a player\n", 2);
	else if (n == 14)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	else if (n == 15)
		ft_putstr_fd("Error: No player specified in args\n", 2);
	else if (n == 16)
		ft_putstr_fd("Error: -v must be followed by a number\n", 2);
	else if (n == 17)
		ft_putstr_fd("Error: Too many processes\n", 2);
	else if (n == 18)
		ft_putstr_fd("Error: Player is too small\n", 2);
	else if (n == 19)
		ft_putstr_fd("Error: Code size differ from what its header says\n", 2);
	return (1);
}

void		ft_error(t_flags *f, int n)
{
	free_processes(f);
	if (!n)
		ft_putstr_fd("Error: There are too many players !\n", 2);
	else if (n == 1)
		ft_putstr_fd("Error: Size of player is too big\n", 2);
	else if (n == 2)
		ft_putstr_fd("Error: Couldn't open file\n", 2);
	else if (n == 3)
		ft_putstr_fd("Error: Couldn't read file\n", 2);
	else if (n == 4)
		ft_putstr_fd("Error: Couldn't close file\n", 2);
	else if (n == 5)
		ft_putstr_fd("Error: Players numbers can't be the same\n", 2);
	else if (n == 6)
		ft_putstr_fd("Error: -n must be followed by a number and a file\n", 2);
	else if (n == 7)
		ft_putstr_fd("Error: -n flag must be followed by a number\n", 2);
	else if (n == 8)
		ft_putstr_fd("Error: COREWAR_EXEC_MAGIC is not the same\n", 2);
	else if (n == 9)
		ft_putstr_fd("Error: File must be a .cor\n", 2);
	else if (ft_error_next(n))
		;
	exit(1);
}
