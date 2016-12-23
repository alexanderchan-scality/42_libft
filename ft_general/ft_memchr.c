/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 23:28:49 by achan             #+#    #+#             */
/*   Updated: 2016/12/03 11:53:02 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

void	*ft_memchr(void const *b, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	t;

	d = (unsigned char *)b;
	t = (unsigned char)c;
	while (n--)
	{
		if (*d == t)
			return ((void *)d);
		++d;
	}
	return (NULL);
}
