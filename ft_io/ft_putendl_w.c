/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 06:44:50 by achan             #+#    #+#             */
/*   Updated: 2016/12/23 15:05:13 by Arekisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putendl_w(char const *s)
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
		write(1, s, size);
		s += size;
	}
	write(1, "\n", 1);
}
