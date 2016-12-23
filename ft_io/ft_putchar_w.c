/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 06:33:34 by achan             #+#    #+#             */
/*   Updated: 2016/12/23 14:17:05 by Arekisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putchar_w(int const c)
{
	int				size;
	unsigned char	t[4];

	size = ft_utf_encode(c, (int *)t);
	write(1, t, size);
}
