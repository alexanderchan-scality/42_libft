/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:41:00 by achan             #+#    #+#             */
/*   Updated: 2016/12/03 12:12:53 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t			size;
	unsigned char	t;

	t = (unsigned char)c;
	size = ft_strlen(s);
	s = s + size;
	size++;
	while (size--)
	{
		if (*s == t)
			return ((char *)s);
		--s;
	}
	return (NULL);
}
