/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 00:10:41 by achan             #+#    #+#             */
/*   Updated: 2016/12/01 05:48:37 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strdup(char const *s)
{
	size_t	size;
	char	*ret;

	size = ft_strlen(s);
	if ((ret = (char *)malloc(sizeof(char) * (size + 1))))
	{
		while ((*ret++ = *s++))
			;
		return (ret - (size + 1));
	}
	return (NULL);
}
