/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:31:22 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 08:39:03 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (p1 > p2)
	{
		p1 += n;
		p2 += n;
		while (n--)
			*--p1 = *--p2;
	}
	else
	{
		while (n--)
			*p1++ = *p2++;
	}
	return (dst);
}
