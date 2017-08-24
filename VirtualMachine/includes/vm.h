/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:29:32 by plogan            #+#    #+#             */
/*   Updated: 2017/08/23 16:37:56 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# define PROG_START (PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
# define TOTAL_SIZE (CHAMP_MAX_SIZE + PROG_START)
# define BUFF_SIZE 1024
# define MASK(x) (x & 0xFF)
# define M_S MEM_SIZE
# define MODULO_MEMORY(x) ((x) % M_S < 0 ? M_S + (x) % M_S : (x) % M_S)
# define MODULO_IDX(x) ((x) % IDX_MOD)
# define RR 01
# define DD 11
# define II 10

typedef struct	s_arena
{
	char	value;
}				t_arena;

typedef struct	s_player
{
	char			*argv;
	int				nb;
	int				nb_was_defined;
	int				last_nb_process;
	int				index;
	int				weight;
	int				is_alive;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char			prog[CHAMP_MAX_SIZE + 1];
	char			data[TOTAL_SIZE + 1];
}				t_player;

typedef struct	s_process
{
	int					is_head;
	int					i;
	struct s_player		*player;
	int					nb_lives;
	int					nb_process;
	int					op_to_do;
	int					nb_jump_if_fail;
	int					is_alive;
	int					is_running;
	int					is_waiting_for_n_cycles;
	int					carry;
	unsigned int		reg[REG_NUMBER];
	struct s_process	*next;
}				t_process;

typedef struct	s_adresses
{
	int	adress1;
	int	adress2;
	int	sum;
}				t_adresses;

typedef struct	s_flags
{
	int					argc;
	char				**argv;
	int					nb_cycles_done;
	int					nb_cycles_done_since_start;
	int					nb_cycles_to_die;
	int					nb_lives_in_round;
	int					print_aff;
	int					print_operations;
	int					print_cycles;
	int					print_moves;
	int					print_lives;
	int					nb_checks_wo_decrement;
	int					nb_players;
	int					op_error;
	int					will_dump;
	int					dump_value;
	struct s_arena		arena[MEM_SIZE];
	struct s_player		players[MAX_PLAYERS];
	struct s_player		*last_player_alive;
	struct s_process	*first_process;
	struct s_op			op_tab[16];
}				t_flags;

typedef struct	s_ft_op
{
	void		(*ft)(t_flags *f, t_process *process);
}				t_ft_op;

void			init_ft_op_tab(t_ft_op *op_tab, int *run);
void			free_processes(t_flags *f);
void			print_value(t_flags *f, int value, int type, int print_r);
void			init_flags(t_flags *f, int argc, char **argv);
void			init_op_tab(t_flags *f);
void			parse_args(t_flags *f, int argc, char **argv);
void			check_file_name(t_flags *f, char *str);
void			check_exec_magic(t_flags *f, int i);
void			init_player(t_flags *f, char *file, int nb);
void			make_op(t_flags *f, t_process *process, t_ft_op *ft_op);
void			start_op(t_flags *f, t_process *process);
void			init_arena(t_flags *f);
void			print_arena(t_flags *f);
void			init_processes(t_flags *f);
void			check_end_of_cycles(t_flags *f, int *run);
void			launch_processes(t_flags *f);
void			recalculate_players_nb(t_flags *f);
void			op_live(t_flags *f, t_process *process);
void			op_ld(t_flags *f, t_process *process);
void			op_ldi(t_flags *f, t_process *process);
void			op_lld(t_flags *f, t_process *process);
void			op_lldi(t_flags *f, t_process *process);
void			op_aff(t_flags *f, t_process *process);
void			op_add(t_flags *f, t_process *process);
void			op_sub(t_flags *f, t_process *process);
void			op_sti(t_flags *f, t_process *process);
void			op_st(t_flags *f, t_process *process);
void			op_and(t_flags *f, t_process *process);
void			op_xor(t_flags *f, t_process *process);
void			op_or(t_flags *f, t_process *process);
void			op_zjmp(t_flags *f, t_process *process);
void			op_fork(t_flags *f, t_process *process);
void			op_lfork(t_flags *f, t_process *process);
void			make_fork(t_flags *f, t_process *process, int is_long);
void			make_ldi(t_flags *f, t_process *process, int is_long, int ocp);
void			ft_usage(void);
void			ft_error(t_flags *f, int n);
void			print_last_player_alive(t_flags *f);
void			print_all_players(t_flags *f);
int				check_player_nb(t_flags *f, int nb);
int				check_op(int op);
int				check_op_args(t_flags *f, t_process *process);
int				get_player_id_for_biggest_nb(t_flags *f, int last_placed,
		int *value_to_place);
int				move_index(t_flags *f, t_process *process, int nb, int print);
int				get_dir(t_flags *f, int index, int size);
int				get_reg_id(t_flags *f, int index);
int				get_ind(t_flags *f, t_process *process, int index, int use_idx);
int				get_next_index(t_flags *f, t_process *process, int use_op_code);
int				get_value_var_4b(t_flags *f, t_process *process, int *index,
		char type);
int				get_value_var_2b(t_flags *f, t_process *process, int *index,
		char type);
int				is_reg(int i);

#endif
