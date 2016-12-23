/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:19:43 by achan             #+#    #+#             */
/*   Updated: 2016/12/03 11:54:52 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	t;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	t = (unsigned char)c;
	while (n--)
	{
		*p1 = *p2;
		if (*p2 == t)
			return ((void *)(p1 + 1));
		++p1;
		++p2;
	}
	return (NULL);
}
