/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_w_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 06:35:52 by achan             #+#    #+#             */
/*   Updated: 2016/12/23 14:18:07 by Arekisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putchar_w_fd(int const c, int fd)
{
	int				size;
	unsigned char	t[4];

	size = ft_utf_encode(c, (int *)t);
	write(fd, t, size);
}
