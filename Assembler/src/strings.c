/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:22:03 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/24 17:37:15 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_string(char **line, int max_len)
{
	char	*str;
	int		i;

	if (**line != '"')
		return (NULL);
	(*line)++;
	str = ft_strnew(max_len);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (**line != '"' && **line != 0 && i < max_len)
		str[i++] = *((*line)++);
	if (**line != '"')
	{
		free(str);
		return (NULL);
	}
	(*line)++;
	while (i < max_len)
		str[i++] = 0;
	return (str);
}

int		get_prog_name(char **line, char **prog_name)
{
	int len;

	len = ft_strlen(NAME_CMD_STRING);
	if (ft_strnequ(*line, NAME_CMD_STRING, len) != 1 ||
	((*line)[len] != ' ' && (*line)[len] != '\t'))
		return (-1);
	if (*prog_name != NULL)
	{
		ft_printf(2, "Program name is already set\n");
		return (-2);
	}
	*line += len + 1;
	ignore_spaces(line);
	*prog_name = get_string(line, PROG_NAME_LENGTH);
	if (*prog_name == NULL)
	{
		ft_printf(2, "Invalid program name\n");
		return (-2);
	}
	ignore_spaces(line);
	return (**line == 0 || **line == COMMENT_CHAR ? 0 : -2);
}

int		get_description(char **line, char **description)
{
	int len;

	len = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strnequ(*line, COMMENT_CMD_STRING, len) != 1 ||
	((*line)[len] != ' ' && (*line)[len] != '\t'))
		return (-1);
	if (*description != NULL)
	{
		ft_printf(2, "Program description is already set\n");
		return (-2);
	}
	*line += len + 1;
	ignore_spaces(line);
	*description = get_string(line, COMMENT_LENGTH);
	if (*description == NULL)
	{
		ft_printf(2, "Invalid program description\n");
		return (-2);
	}
	ignore_spaces(line);
	return (**line == 0 || **line == COMMENT_CHAR ? 0 : -2);
}
