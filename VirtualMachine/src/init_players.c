/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:25:34 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 15:26:26 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		read_file_length(t_flags *f, char *name)
{
	int		fd;
	int		ret;
	char	tmp[BUFF_SIZE];
	int		len;

	len = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error(f, 2);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
		len += ret;
	if (ret < 0)
		ft_error(f, 3);
	if (close(fd) < 0)
		ft_error(f, 4);
	return (len);
}

static char		*read_file(t_flags *f, char *name, int *len_ret)
{
	char	*data;
	int		fd;
	int		ret;
	int		len;

	len = read_file_length(f, name);
	if (!(data = ft_memalloc(TOTAL_SIZE + 1)))
		ft_error(f, 14);
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error(f, 2);
	if ((ret = read(fd, data, len)) < 0)
		ft_error(f, 3);
	if (close(fd) < 0)
		ft_error(f, 4);
	*len_ret = len;
	return (data);
}

static void		init_player_start(t_flags *f, int len, int i)
{
	if (len < 0)
		ft_error(f, 18);
	ft_memset(f->players[i].data, 0, TOTAL_SIZE + 1);
	ft_memset(f->players[i].name, 0, PROG_NAME_LENGTH + 1);
	ft_memset(f->players[i].prog, 0, CHAMP_MAX_SIZE + 1);
	ft_memset(f->players[i].comment, 0, COMMENT_LENGTH + 1);
}

void			init_player_next(t_flags *f, char *file, int i)
{
	char	*champ;
	char	*sav;
	int		len;

	champ = read_file(f, file, &len);
	len = len - 16 - COMMENT_LENGTH - PROG_NAME_LENGTH;
	init_player_start(f, len, i);
	ft_memcpy(f->players[i].data, champ, TOTAL_SIZE);
	check_exec_magic(f, i);
	sav = champ;
	champ = champ + 4;
	ft_strncpy(f->players[i].name, champ, PROG_NAME_LENGTH);
	champ = champ + 4 + PROG_NAME_LENGTH;
	f->players[i].weight = (((*champ) & 0xFF) << 24)
		| ((*(champ + 1) & 0xFF) << 16) | ((*(champ + 2) & 0xFF) << 8)
		| (*(champ + 3) & 0xFF);
	if (f->players[i].weight != len)
		ft_error(f, 19);
	champ = champ + 4;
	ft_strncpy(f->players[i].comment, champ, COMMENT_LENGTH);
	champ = champ + 4 + COMMENT_LENGTH;
	if (len > CHAMP_MAX_SIZE)
		ft_error(f, 1);
	ft_memcpy(f->players[i].prog, champ, len);
	free(sav);
}

void			init_player(t_flags *f, char *file, int nb)
{
	int i;

	i = f->nb_players;
	check_file_name(f, file);
	if (i >= MAX_PLAYERS || i == INT_MAX)
		ft_error(f, 0);
	f->players[i].nb = nb;
	if (nb > 0)
	{
		f->players[i].nb_was_defined = 1;
		if (!check_player_nb(f, nb))
			ft_error(f, 5);
	}
	else
		f->players[i].nb_was_defined = 0;
	f->players[i].argv = file;
	f->players[i].last_nb_process = 0;
	f->players[i].is_alive = 1;
	init_player_next(f, file, i);
}
