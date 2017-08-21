/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:20:53 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/10 20:38:41 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	get_param(t_asm *a, unsigned char *pow4, t_arg_type type)
{
	if ((T_REG & type) == T_REG && get_reg(a) == 0)
		a->types_byte += REG_CODE * *pow4;
	else if ((T_DIR & type) == T_DIR && get_dir(a) == 0)
		a->types_byte += DIR_CODE * *pow4;
	else if ((T_IND & type) == T_IND && get_ind(a) == 0)
		a->types_byte += IND_CODE * *pow4;
	else
	{
		ft_printf(2, "Invalid parameter\n");
		return (-1);
	}
	*pow4 /= 4;
	return (0);
}

int	get_params(t_asm *a)
{
	int				i;
	unsigned char	pow4;

	i = 0;
	pow4 = ft_pow(4, 3);
	while (i < g_op_tab[a->i_op].nb_params)
	{
		if (get_param(a, &pow4, g_op_tab[a->i_op].types[i]) == -1)
			return (-1);
		if (i < g_op_tab[a->i_op].nb_params - 1)
		{
			ignore_spaces(&a->line);
			if (a->line[0] == SEPARATOR_CHAR)
				a->line++;
			else
			{
				ft_printf(2, "Missing %c\n", SEPARATOR_CHAR);
				return (-1);
			}
			ignore_spaces(&a->line);
		}
		i++;
	}
	return (0);
}

int	get_instruction(t_asm *a)
{
	if (get_opcode(a) == -1)
		return (-1);
	ignore_spaces(&a->line);
	a->i_line_byte = 1;
	a->types_byte = 0;
	if (g_op_tab[a->i_op].type_required)
		a->i_line_byte = 2;
	if (get_params(a) == -1)
		return (-2);
	if (g_op_tab[a->i_op].type_required)
		add_value_to_bytecode(a->bytecode + a->pc + 1, a->types_byte, 1);
	a->pc += a->i_line_byte;
	if (a->pc > 4 + PROG_NAME_LENGTH + 4 +
	4 + COMMENT_LENGTH + 4 + MAX_PROG_SIZE)
	{
		ft_printf(2, "The program is too long\n");
		return (-2);
	}
	ignore_spaces(&a->line);
	return (a->line[0] == 0 || a->line[0] == COMMENT_CHAR ? 0 : -2);
}
