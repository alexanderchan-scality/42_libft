/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:50:35 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 08:25:32 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			ret[i] = (*f)(s[i]);
			i++;
		}
		ret[size] = 0;
		return (ret);
	}
	return (NULL);
}
