/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:28:55 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 11:15:09 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))))
	{
		i = 0;
		while (i++ < len)
			ret[i - 1] = s[i - 1 + start];
		ret[len] = 0;
		return (ret);
	}
	return (NULL);
}
