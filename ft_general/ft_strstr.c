/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 07:39:54 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 07:57:43 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	char const	*p1;
	char const	*p2;

	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		p1 = s1;
		p2 = s2;
		while (*p2 && (*p2 == *s1))
		{
			p2++;
			s1++;
		}
		if (!*p2)
			return ((char *)p1);
		s1 = p1 + 1;
	}
	return (NULL);
}
