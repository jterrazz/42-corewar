/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:21:08 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/24 18:25:02 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int argc, char **argv)
{
	t_asm	a;
	int		len;
	int		r;

	find_nb_bytes_i_reg(&a.nb_bytes_i_reg);
	if (init_asm(&a) == -1)
		return (0);
	if (argc != 2)
		return (end(&a, "usage : ./asm sourcefile.s", 1));
	len = ft_strlen(argv[1]);
	if (len < 3 || ft_strnequ(&argv[1][len - 2], ".s", 2) != 1)
		return (end(&a, "Missing .s extension", 2));
	if ((a.fd = open(argv[1], O_RDONLY)) == -1)
		return (end(&a, "Could not open input file", 2));
	while ((r = get_line(&a)) == 1)
		;
	if (r == -1)
		return (end(&a, "", 2));
	add_header_to_bytecode(a.bytecode, a.pc, a.prog_name, a.description);
	if (replace_calls(a.bytecode, a.declarations, a.calls) == -1)
		return (end(&a, "", 2));
	if (write_bytecode(a.bytecode, a.pc, argv[1], len) == -1)
		return (end(&a, "", 2));
	return (end(&a, "Done.", 1));
}

void		find_nb_bytes_i_reg(int *nb_bytes_i_reg)
{
	*nb_bytes_i_reg = 1;
	while (ft_pow(2, *nb_bytes_i_reg * 8) - 1 < REG_NUMBER)
		(*nb_bytes_i_reg)++;
}

int			init_asm(t_asm *a)
{
	a->bytecode = malloc((4 + PROG_NAME_LENGTH + 4 +
	4 + COMMENT_LENGTH + 4 + MAX_PROG_SIZE + 1 + 1 +
	4 * ft_max(a->nb_bytes_i_reg, ft_max(DIR_SIZE, IND_SIZE))) *
	sizeof(unsigned char));
	if (a->bytecode == NULL)
		return (-1);
	a->pc = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	a->i_line = 1;
	a->fd = -1;
	a->prog_name = NULL;
	a->description = NULL;
	a->declarations = NULL;
	a->calls = NULL;
	return (0);
}

int			end(t_asm *a, char *str, int output)
{
	free(a->bytecode);
	if (a->fd != -1)
		close(a->fd);
	free(a->prog_name);
	free(a->description);
	free_declarations(a->declarations);
	free_calls(a->calls);
	ft_printf(output, "%s\n", str);
	return (0);
}

long long	ft_pow(long long a, unsigned long long b)
{
	long long result;

	result = 1;
	while (b > 0)
	{
		result *= a;
		b--;
	}
	return (result);
}
