/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:32:59 by achan             #+#    #+#             */
/*   Updated: 2016/12/22 14:22:31 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

size_t	ft_strlcat(char *s1, char const *s2, size_t size)
{
	size_t	t_size;
	size_t	l1;
	size_t	l2;

	s1 += (l1 = ft_strlen(s1));
	l2 = ft_strlen(s2);
	if (!size)
		return (l2);
	if (size - 1 < l1)
		return (size + l2);
	if (size - 1 == l1)
		return (size - 1 + l2);
	t_size = size - 1 - l1;
	while (*s2 && t_size)
	{
		*s1++ = *s2++;
		t_size--;
	}
	*s1 = 0;
	return (l1 + l2);
}
