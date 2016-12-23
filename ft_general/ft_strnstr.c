/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 07:52:20 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 08:11:59 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t len)
{
	char const	*p1;
	char const	*p2;
	size_t		i;

	if (!*s2)
		return ((char *)s1);
	while (*s1 && len)
	{
		i = len;
		p1 = s1;
		p2 = s2;
		while (*p2 && (*p2 == *s1) && len)
		{
			p2++;
			s1++;
			len--;
		}
		if (!*p2)
			return ((char *)p1);
		s1 = p1 + 1;
		len = i - 1;
	}
	return (NULL);
}
