/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:05:14 by fbonnin           #+#    #+#             */
/*   Updated: 2017/07/23 16:12:47 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_i_buff(t_gnl *s, int fd)
{
	int i_buff;

	i_buff = 0;
	while (i_buff < s->nb_files && s->files[i_buff] != fd)
		i_buff++;
	if (i_buff < s->nb_files)
		return (i_buff);
	if (s->nb_files == GNL_MAX_NB_FILES)
		return (-1);
	s->files[s->nb_files++] = fd;
	return (i_buff);
}

static int	ft_buff_is_empty(t_gnl *s, int i_buff)
{
	return (s->i_byte[i_buff] >= s->nb_bytes_read[i_buff]);
}

static int	ft_update_buff(t_gnl *s, int i_buff)
{
	if (ft_buff_is_empty(s, i_buff))
	{
		s->nb_bytes_read[i_buff] =
		read(s->files[i_buff], s->buff[i_buff], GNL_BUFF_SIZE);
		s->i_byte[i_buff] = 0;
		return (s->nb_bytes_read[i_buff]);
	}
	return (0);
}

static int	ft_load_line(t_gnl *s, int i_buff)
{
	s->line_size = 0;
	while (s->buff[i_buff][s->i_byte[i_buff]] != '\n'
	&& !ft_buff_is_empty(s, i_buff))
	{
		if (s->line_size >= GNL_MAX_LINE_SIZE)
			return (-1);
		s->line[s->line_size++] = s->buff[i_buff][s->i_byte[i_buff]];
		s->i_byte[i_buff]++;
		if (ft_update_buff(s, i_buff) == -1)
			return (-1);
	}
	s->i_byte[i_buff]++;
	return (1);
}

int			ft_get_next_line(const int fd, char **line)
{
	static t_gnl	s;
	int				i_buff;
	int				i_line;

	if (GNL_BUFF_SIZE < 1 || GNL_MAX_NB_FILES < 1 || GNL_MAX_LINE_SIZE < 1)
		return (-1);
	i_buff = ft_get_i_buff(&s, fd);
	if (i_buff == -1)
		return (-1);
	if (ft_update_buff(&s, i_buff) == -1)
		return (-1);
	if (ft_buff_is_empty(&s, i_buff))
		return (0);
	if (ft_load_line(&s, i_buff) == -1)
		return (-1);
	*line = ft_strnew(s.line_size);
	if (*line == NULL)
		return (-1);
	i_line = 0;
	while (i_line < s.line_size)
	{
		(*line)[i_line] = s.line[i_line];
		i_line++;
	}
	return (1);
}
