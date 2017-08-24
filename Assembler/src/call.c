/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:20:43 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/24 18:39:18 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_call(char **line)
{
	char *result;

	if (**line != LABEL_CHAR)
		return (NULL);
	result = get_label(*line + 1);
	if (result == NULL)
		return (NULL);
	*line += 1 + ft_strlen(result);
	return (result);
}

int		add_call(t_asm *a)
{
	char	*label;
	t_call	*call;

	label = get_call(&a->line);
	if (label == NULL)
		return (0);
	call = malloc(sizeof(t_call));
	if (call == NULL)
	{
		a->line -= 1 + ft_strlen(label);
		free(label);
		return (0);
	}
	call->label = label;
	call->pc = a->pc;
	call->i_line_byte = a->i_line_byte;
	call->nb_bytes = a->nb_bytes;
	call->i_line = a->i_line;
	call->next = a->calls;
	a->calls = call;
	return (1);
}

int		replace_calls(unsigned char *bytecode,
t_declaration *declarations, t_call *calls)
{
	t_declaration	*declaration;
	t_call			*call;

	call = calls;
	while (call != NULL)
	{
		declaration = find_declaration(declarations, call->label);
		if (declaration == NULL)
		{
			ft_printf(2, "Label %s undeclared\n", call->label);
			ft_printf(2, "Error at line %d\n", call->i_line);
			return (-1);
		}
		add_value_to_bytecode(bytecode + call->pc + call->i_line_byte,
		declaration->pc - call->pc, call->nb_bytes);
		call = call->next;
	}
	return (0);
}

void	free_calls(t_call *calls)
{
	t_call *call;
	t_call *next;

	call = calls;
	while (call != NULL)
	{
		next = call->next;
		free(call->label);
		free(call);
		call = next;
	}
}
