// header

#include "vm.h"

static int get_next_arg_if_nb(t_flags *f, int *i, int err_nb)
{
	int j;
	int argc;
	char **argv;
	long nb;

	j = 0;
	argc = f->argc;
	argv = f->argv;
	if (*i + 1 >= argc) // with = ???
		ft_error(f, 6);
	(*i)++;
	while (argv[*i][j])
	{
		if (!ft_isdigit(argv[*i][j]))
			ft_error(f, err_nb);
		j++;
	}
	nb = ft_atoi_long(argv[*i]); //check my ft_atoilong can handle min
	if (nb < INT_MIN || nb > INT_MAX) // TODO probably do in unsigned // DO if nb < 1
		ft_error(f, 10);
	return (nb);
}

static void handle_dump(int *i, t_flags *f)
{
	f->will_dump = 1;
	f->dump_value = get_next_arg_if_nb(f, i, 11);
}
//TODO ft_error dont forget to free everything
void parse_args(t_flags *f, int argc, char **argv)
{
	int i;
	int nb;

	i = 1;
	f->print_cycles = 0; // do real check
	f->print_operations = 0; // do real check
	f->print_moves = 0; // do real check
	if (!ft_strcmp(argv[i], "-dump")) // check also argc
	{
		handle_dump(&i, f);
		i++;
	}
	// check with -dump and no players
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			nb = get_next_arg_if_nb(f, &i, 7);
			if (nb < 1)
				ft_error(f, 12);
			i++;
			if (i >= argc)
				ft_error(f, 13);
			init_player(f, argv[i], nb);
		}
		else
			init_player(f, argv[i], -1);
		i++;
		f->nb_players += 1;
	}
}
