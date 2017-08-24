/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:20:28 by fbonnin           #+#    #+#             */
/*   Updated: 2017/08/24 18:24:10 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "fcntl.h"
# include "libft/libft.h"
# include "op.h"

# define MAX_PROG_SIZE MEM_SIZE
# define POW_2_63_M1 9223372036854775807
# define _POW_2_63_P1 -9223372036854775807

typedef struct	s_op
{
	char		*name;
	int			nb_params;
	t_arg_type	types[4];
	int			opcode;
	int			nb_cycles;
	char		*description;
	int			type_required;
	int			index_expected;
}				t_op;

typedef struct	s_declaration
{
	char					*label;
	int						pc;
	struct s_declaration	*next;
}				t_declaration;

typedef struct	s_call
{
	char			*label;
	int				pc;
	int				i_line_byte;
	int				nb_bytes;
	int				i_line;
	struct s_call	*next;
}				t_call;

typedef struct	s_asm
{
	int				nb_bytes_i_reg;
	unsigned char	*bytecode;
	int				pc;
	int				i_line_byte;
	int				i_line;
	int				fd;
	char			*line;
	char			*prog_name;
	char			*description;
	int				i_op;
	unsigned char	types_byte;
	int				nb_bytes;
	t_declaration	*declarations;
	t_call			*calls;
}				t_asm;

extern t_op		g_op_tab[17];

void			find_nb_bytes_i_reg(int *nb_bytes_i_reg);
int				init_asm(t_asm *a);
int				end(t_asm *a, char *str, int output);
long long		ft_pow(long long a, unsigned long long b);

void			add_value_to_bytecode(unsigned char *bytecode,
				long long value, int nb_bytes);
void			add_value_to_bytecode_2(unsigned char *bytecode,
				int nb_bytes, int neg);
void			add_header_to_bytecode(unsigned char *bytecode,
				int pc, char *prog_name, char *description);
void			add_strings_to_bytecode(unsigned char *bytecode,
				char *prog_name, char *description);
int				write_bytecode(unsigned char *bytecode, int pc,
				char *input_name, int len);

int				get_line(t_asm *a);
int				end_line(int *i_line, char *line, int r);
void			ignore_spaces(char **line);

char			*get_string(char **line, int max_len);
int				get_prog_name(char **line, char **prog_name);
int				get_description(char **line, char **description);

int				get_opcode(t_asm *a);
long long		get_number(char **line, long long mini, long long maxi);
char			*get_label(char *line);

int				get_reg(t_asm *a);
int				get_dir(t_asm *a);
int				get_ind(t_asm *a);

int				get_param(t_asm *a, unsigned char *pow4, t_arg_type type);
int				get_params(t_asm *a);
int				get_instruction(t_asm *a);

char			*get_declaration(char **line);
t_declaration	*find_declaration(t_declaration *declarations, char *label);
int				add_declaration(t_declaration **declarations,
				char **line, int pc);
void			free_declarations(t_declaration *declarations);

char			*get_call(char **line);
int				add_call(t_asm *a);
int				replace_calls(unsigned char *bytecode,
				t_declaration *declarations, t_call *calls);
void			free_calls(t_call *calls);

#endif
