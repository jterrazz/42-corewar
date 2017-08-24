/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:52:10 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/18 15:07:38 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include "unistd.h"
# include "stdlib.h"
# include "string.h"

# include "ft_get_next_line.h"

void			*ft_memset(void *address, int value, size_t n);
void			ft_bzero(void *address, size_t n);
void			*ft_memcpy(void *destination, const void *source, size_t n);
void			*ft_memccpy(void *destination, const void *source,
					int c, size_t n);
void			*ft_memmove(void *destination, const void *source, size_t n);
void			*ft_memchr(const void *address, int value, size_t n);
int				ft_memcmp(const void *address1, const void *address2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, char c);
char			*ft_strrchr(const char *s, char c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_std_list
{
	void				*content;
	size_t				content_size;
	struct s_std_list	*next;
}				t_std_list;

t_std_list		*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_std_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_std_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_std_list **alst, t_std_list *new_elem);
void			ft_lstiter(t_std_list *lst, void (*f)(t_std_list *elem));
t_std_list		*ft_lstmap(t_std_list *lst, t_std_list *(*f)(t_std_list *elem));
void			ft_lst_push_back(t_std_list **alst, t_std_list *new_elem);

int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
void			ft_stolower(char *s);
void			ft_stoupper(char *s);

#endif
