/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 05:44:20 by achan             #+#    #+#             */
/*   Updated: 2016/12/26 23:03:49 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <unistd.h>
# include "ft_linkedlist.h"
# include "ft_general.h"

int					ft_utf_encode(int c, int *output);

void				ft_putchar(char const c);
void				ft_putchar_w(int const c);
void				ft_putchar_fd(char const c, int fd);
void				ft_putchar_w_fd(int const c, int fd);

void				ft_putstr(char const *s);
void				ft_putstr_w(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr_w_fd(char const *s, int fd);

void				ft_putendl(char const *s);
void				ft_putendl_w(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl_w_fd(char const *s, int fd);

void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);

# define BUFF_SIZE	4096

typedef struct		s_fd_state
{
	int				fd;
	size_t			rem_size;
	char			rem[BUFF_SIZE];
}					t_fd_state;

int					ft_gnl(const int fd, char **line);
int					fd_cmp(void *fd_state, void *fd);
t_fd_state			*fd_new(int fd);
#endif
