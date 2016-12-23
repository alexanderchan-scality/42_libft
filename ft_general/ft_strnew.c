/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:33:38 by achan             #+#    #+#             */
/*   Updated: 2016/11/28 15:20:42 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ret;

	if ((ret = (char *)malloc(sizeof(char) * (size + 1))))
	{
		i = 0;
		while (i++ <= size)
			ret[i - 1] = '\0';
		return (ret);
	}
	return (NULL);
}
