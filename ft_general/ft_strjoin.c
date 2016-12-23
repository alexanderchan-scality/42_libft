/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:38:15 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 10:55:26 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

static size_t	get_size(char const *s1, char const *s2)
{
	size_t	size;

	size = 0;
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	return (size);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	size = get_size(s1, s2);
	if ((ret = (char *)malloc(sizeof(char) * (size + 1))))
	{
		i = 0;
		if (s1)
		{
			while (*s1)
				ret[i++] = *s1++;
		}
		if (s2)
		{
			while (*s2)
				ret[i++] = *s2++;
		}
		ret[size] = '\0';
		return (ret);
	}
	return (NULL);
}
