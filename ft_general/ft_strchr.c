/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:26:23 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 05:41:56 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strchr(char const *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if (!((unsigned char)c))
		return ((char *)s + size);
	while (*s)
	{
		if (*s++ == (unsigned char)c)
			return ((char *)s - 1);
	}
	return (NULL);
}
