/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:59:39 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 09:09:59 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

static int		is_white(char const c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	while (is_white(*s))
		s++;
	size = ft_strlen(s);
	i = size - 1;
	while (is_white(s[i--]) && size)
		size--;
	if ((ret = (char *)malloc(sizeof(char) * (size + 1))))
	{
		i = 0;
		while (i < size)
			ret[i++] = *s++;
		ret[size] = 0;
		return (ret);
	}
	return (NULL);
}
