#include "vm.h"

static int		read_file_length(t_flags *f, char *name)
{
	int fd;
	int ret;
	char tmp[BUFF_SIZE];
	int len;

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

static char		*read_file(t_flags *f, char *name)
{
	char *data;
	int fd;
	int ret;
	int len;

	len = read_file_length(f, name);
	data = ft_memalloc(TOTAL_SIZE + 1); // TODO check with big big players
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error(f, 2);
	if ((ret = read(fd, data, len)) < 0)
		ft_error(f, 3);
	if (close(fd) < 0)
		ft_error(f, 4);
	return (data);
}

// TODO Not sure if we have to check name and comment chars
// TODO CHECK PLAYER NUMBER MUST BE > 0

void			init_player_next(t_flags *f, char *file, int i)
{
	char *champ;
	char *sav;

	champ = read_file(f, file);
	ft_memset(f->players[i].data, 0, TOTAL_SIZE + 1);
	ft_memcpy(f->players[i].data, champ, TOTAL_SIZE);
	check_exec_magic(f, i);
	ft_memset(f->players[i].name, 0, PROG_NAME_LENGTH + 1);
	ft_memset(f->players[i].comment, 0, COMMENT_LENGTH + 1);
	ft_memset(f->players[i].prog, 0, CHAMP_MAX_SIZE + 1);
	sav = champ;
	champ = champ + 4;
	ft_strncpy(f->players[i].name, champ, PROG_NAME_LENGTH);
	champ = champ + 4 + PROG_NAME_LENGTH;
	f->players[i].weight = (*champ << 24 & 0xFF)
		| (*(champ + 1) << 16 & 0xFF)
		| (*(champ + 2) << 8 & 0xFF)
		| (*(champ + 3) & 0xFF);
	champ = champ + 4;
	ft_strncpy(f->players[i].comment, champ, COMMENT_LENGTH);
	champ = champ + 4 + COMMENT_LENGTH;
	if (ft_strlen(champ) > CHAMP_MAX_SIZE)
		ft_error(f, 1);
	ft_memcpy(f->players[i].prog, champ, CHAMP_MAX_SIZE); //TODO check also the length is smaller
	free(sav);
}

void			init_player(t_flags *f, char *file, int nb)
{
	int i;

	i = f->nb_players;
	check_file_name(f, file);
	if (i >= MAX_PLAYERS) //TODO check >>>>>>======== !!!
		ft_error(f, 0);
	f->players[i].nb = nb;
	if (nb > 0)
	{
		f->players[i].nb_was_defined = 1;
		if (!check_player_nb(f, nb))
			ft_error(f, 5);//TODO check it works + msg
	}
	else
		f->players[i].nb_was_defined = 0;
		//Maybe check player has enought length to go after header
	f->players[i].argv = file;
	f->players[i].last_nb_process = 0;
	f->players[i].is_alive = 1;
	init_player_next(f, file, i);
} //TODO ALSO CHECK THE CODING BYTE IS OK
