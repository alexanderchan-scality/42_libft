/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:37:59 by achan             #+#    #+#             */
/*   Updated: 2016/12/24 16:29:25 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

void	*ft_remalloc(void *ptr, size_t s1, size_t s2)
{
	size_t			i;
	unsigned char	*new_ptr;
	unsigned char	*tmp;

	if (!ptr)
		s1 = 0;
	tmp = (unsigned char *)ptr;
	if (s1 == s2)
		return (ptr);
	if (!(new_ptr = (unsigned char *)malloc(sizeof(unsigned char) * s2)))
		return (NULL);
	i = 0;
	while (i < s2)
	{
		if (i < s1)
			new_ptr[i] = tmp[i];
		else
			new_ptr[i] = 0;
		++i;
	}
	if (ptr)
		free(ptr);
	return ((void *)new_ptr);
}
