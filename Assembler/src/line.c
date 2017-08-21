/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:21:00 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/10 20:21:02 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_line(t_asm *a)
{
	char	*line;
	int		r;

	if (ft_get_next_line(a->fd, &line) != 1)
		return (0);
	a->line = line;
	ignore_spaces(&a->line);
	r = get_prog_name(&a->line, &a->prog_name);
	if (r == 0)
		return (end_line(&a->i_line, line, 1));
	if (r == -2)
		return (end_line(&a->i_line, line, -1));
	r = get_description(&a->line, &a->description);
	if (r == 0)
		return (end_line(&a->i_line, line, 1));
	if (r == -2)
		return (end_line(&a->i_line, line, -1));
	if (add_declaration(&a->declarations, &a->line, a->pc) == -1)
		return (end_line(&a->i_line, line, -1));
	ignore_spaces(&a->line);
	if (get_instruction(a) == -2)
		return (end_line(&a->i_line, line, -1));
	ignore_spaces(&a->line);
	return (end_line(&a->i_line, line,
	a->line[0] == 0 || a->line[0] == COMMENT_CHAR ? 1 : -1));
}

int		end_line(int *i_line, char *line, int r)
{
	if (r == -1)
		ft_printf(2, "Error at line %d\n", *i_line);
	free(line);
	(*i_line)++;
	return (r);
}

void	ignore_spaces(char **line)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
}
