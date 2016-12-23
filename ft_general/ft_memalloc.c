/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:41:59 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 08:23:37 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*ret;

	i = 0;
	if ((ret = (unsigned char *)malloc(size)))
	{
		while (i++ < size)
			ret[i - 1] = 0;
		return ((void *)ret);
	}
	return (NULL);
}
