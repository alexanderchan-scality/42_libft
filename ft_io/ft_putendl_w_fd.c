/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_w_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 06:37:43 by achan             #+#    #+#             */
/*   Updated: 2016/12/23 15:05:24 by Arekisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putendl_w_fd(char const *s, int fd)
{
	int	size;

	if (!s)
		return ;
	while (*s)
	{
		if ((*s & 0x80) == 0x00)
			size = 1;
		else if ((*s & 0xE0) == 0xC0)
			size = 2;
		else if ((*s & 0xF0) == 0xE0)
			size = 3;
		else if ((*s & 0xF8) == 0xF0)
			size = 4;
		write(fd, s, size);
		s += size;
	}
	write(fd, "\n", 1);
}
