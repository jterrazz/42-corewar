/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:20:48 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/10 20:28:10 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*get_declaration(char **line)
{
	char *result;

	result = get_label(*line);
	if (result == NULL)
		return (NULL);
	if ((*line)[ft_strlen(result)] != LABEL_CHAR)
	{
		free(result);
		return (NULL);
	}
	*line += ft_strlen(result) + 1;
	return (result);
}

t_declaration	*find_declaration(t_declaration *declarations, char *label)
{
	t_declaration *declaration;

	declaration = declarations;
	while (declaration != NULL)
	{
		if (ft_strequ(declaration->label, label) == 1)
			return (declaration);
		declaration = declaration->next;
	}
	return (NULL);
}

int				add_declaration(
t_declaration **declarations, char **line, int pc)
{
	char			*label;
	t_declaration	*declaration;

	label = get_declaration(line);
	if (label == NULL)
		return (0);
	if (find_declaration(*declarations, label) != NULL)
	{
		ft_printf(2, "Label %s already exists\n", label);
		free(label);
		return (-1);
	}
	declaration = malloc(sizeof(t_declaration));
	if (declaration == NULL)
	{
		free(label);
		return (-1);
	}
	declaration->label = label;
	declaration->pc = pc;
	declaration->next = *declarations;
	*declarations = declaration;
	return (1);
}

void			free_declarations(t_declaration *declarations)
{
	t_declaration *declaration;
	t_declaration *next;

	declaration = declarations;
	while (declaration != NULL)
	{
		next = declaration->next;
		free(declaration->label);
		free(declaration);
		declaration = next;
	}
}
