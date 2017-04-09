/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 23:01:15 by achan             #+#    #+#             */
/*   Updated: 2017/01/25 11:47:25 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_gnl.h"

static t_fd_state	*fd_new(int fd)
{
	t_fd_state	*ret;

	if (fd < 0)
		return (NULL);
	if (!(ret = (t_fd_state *)malloc(sizeof(t_fd_state))))
		return (NULL);
	ret->fd = fd;
	ret->rem_size = 0;
	ft_bzero(ret->rem, GNL_BUFF_SIZE);
	return (ret);
}

static int			fd_cmp(void *fd_state, void *fd)
{
	t_fd_state	*tmp_state;
	int			*tmp_fd;

	if (!fd_state)
		return (0);
	tmp_state = (t_fd_state *)fd_state;
	tmp_fd = (int *)fd;
	if (tmp_state->fd == *tmp_fd)
		return (1);
	return (0);
}

static int			get_rem_line(char **line, t_fd_state *state,
									size_t *cur_size)
{
	char	*nl_pos;
	size_t	d_size;

	if (state->rem_size > 0)
	{
		free(*line);
		if ((nl_pos = ft_memchr(state->rem, '\n', state->rem_size)))
		{
			d_size = nl_pos - state->rem;
			*cur_size = (state->rem_size -= (d_size + 1));
			*line = (char *)ft_memndup(state->rem, d_size + 1);
			(*line)[d_size] = 0;
			ft_memmove(state->rem, state->rem + d_size + 1, *cur_size);
			return (1);
		}
		else
		{
			*cur_size = state->rem_size;
			*line = ft_memndup(state->rem, *cur_size + 1);
			(*line)[*cur_size] = 0;
			state->rem_size = 0;
			ft_bzero(state->rem, GNL_BUFF_SIZE);
		}
	}
	return (0);
}

static int			get_read_line(char **line,
							t_fd_state *state, size_t *cur_size)
{
	int		ret;
	char	*nl_pos;
	size_t	d_size;
	char	buf[GNL_BUFF_SIZE];

	while ((ret = read(state->fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		if ((nl_pos = ft_memchr(buf, '\n', ret)))
		{
			d_size = nl_pos - buf;
			state->rem_size = ret - (d_size + 1);
			ft_memmove(state->rem, buf + d_size + 1, state->rem_size);
		}
		else
			d_size = ret;
		if (!(*line = ft_remalloc(*line, *cur_size, *cur_size + d_size + 1)))
			return (-1);
		ft_memmove(*line + *cur_size, buf, d_size);
		*cur_size += d_size;
		(*line)[*cur_size] = 0;
		if (nl_pos || ret < GNL_BUFF_SIZE)
			return (1);
	}
	return (ret);
}

int					ft_gnl(const int fd, char **line)
{
	static t_llist	fd_states = {NULL, NULL};
	t_fd_state		*state;
	size_t			cur_size;
	int				read_status;

	if (!line || fd < 0)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char))))
		return (-1);
	line[0][0] = 0;
	cur_size = 0;
	if (ft_llst_empty(&fd_states) ||
		!(state = (ft_llst_find(&fd_states, (int *)&fd, &fd_cmp))))
		ft_llst_pushbck(&fd_states, (state = fd_new(fd)), sizeof(t_fd_state));
	if (get_rem_line(line, state, &cur_size))
		return (1);
	read_status = get_read_line(line, state, &cur_size);
	read_status = (read_status >= 0 && cur_size > 0) ? 1 : read_status;
	if (!read_status && !state->rem_size)
	{
		ft_llst_idel(&fd_states, &(state->fd), (*fd_cmp));
		state = NULL;
	}
	return (read_status);
}
