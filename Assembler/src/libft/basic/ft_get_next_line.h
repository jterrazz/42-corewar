/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:06:07 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/18 13:17:11 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define GNL_BUFF_SIZE 1000
# define GNL_MAX_NB_FILES 100
# define GNL_MAX_LINE_SIZE 100000

typedef struct	s_gnl
{
	char	buff[GNL_MAX_NB_FILES][GNL_BUFF_SIZE];
	int		nb_bytes_read[GNL_MAX_NB_FILES];
	int		i_byte[GNL_MAX_NB_FILES];
	int		files[GNL_MAX_NB_FILES];
	int		nb_files;
	char	line[GNL_MAX_LINE_SIZE];
	int		line_size;
}				t_gnl;

int				ft_get_next_line(const int fd, char **line);

#endif
