/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:03:28 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 09:13:28 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

int	ft_memichr(void const *b, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	t;
	size_t			i;

	d = (unsigned char *)b;
	t = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (*d == t)
			return ((int)i);
		++i;
		++d;
	}
	return (-1);
}
