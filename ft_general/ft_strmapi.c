/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:00:40 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 08:27:23 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if ((ret = (char *)malloc(sizeof(char) * (size + 1))))
	{
		i = 0;
		while (i < size)
		{
			ret[i] = (*f)((unsigned int)i, s[i]);
			i++;
		}
		ret[size] = 0;
		return (ret);
	}
	return (NULL);
}
