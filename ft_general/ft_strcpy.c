/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 00:19:46 by achan             #+#    #+#             */
/*   Updated: 2016/11/30 20:52:58 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

char	*ft_strcpy(char *dst, char const *src)
{
	char	*ret;

	ret = dst;
	while ((*dst++ = *src++))
		;
	return (ret);
}