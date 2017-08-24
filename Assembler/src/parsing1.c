/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:21:52 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/24 17:38:14 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_opcode(t_asm *a)
{
	int		i;
	char	*name;
	int		len;

	i = 0;
	while (g_op_tab[i].opcode != 0)
	{
		name = g_op_tab[i].name;
		len = ft_strlen(name);
		if (ft_strnequ(name, a->line, len) == 1 &&
		(a->line[len] == ' ' || a->line[len] == '\t'))
		{
			a->line += len + 1;
			break ;
		}
		i++;
	}
	if (g_op_tab[i].opcode == 0)
		return (-1);
	a->i_op = i;
	add_value_to_bytecode(a->bytecode + a->pc, g_op_tab[i].opcode, 1);
	return (0);
}

long long	get_number(char **line, long long mini, long long maxi)
{
	long long	result;
	int			sign;
	int			len;

	result = 0;
	sign = 1;
	len = 0;
	if (**line == '-' || **line == '+')
	{
		if (**line == '-')
			sign = -1;
		len = 1;
	}
	if (!ft_isdigit((*line)[len]))
		return (_POW_2_63_P1);
	while (ft_isdigit((*line)[len]))
	{
		result *= 10;
		result += (*line)[len++] - 48;
	}
	result *= sign;
	if (result < mini || result > maxi || result <= _POW_2_63_P1)
		return (_POW_2_63_P1);
	*line += len;
	return (result);
}

char		*get_label(char *line)
{
	char	*result;
	int		len;
	int		i;

	if (ft_strchr(LABEL_CHARS, *line) == NULL || *line == 0)
		return (NULL);
	len = 0;
	while (ft_strchr(LABEL_CHARS, line[len]) != NULL && line[len] != 0)
		len++;
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = line[i];
		i++;
	}
	return (result);
}
