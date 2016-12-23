/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 00:33:07 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 15:59:40 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

void	*ft_memndup(void const *b, size_t n)
{
	void	*ret;

	if (!(ret = ft_memalloc(n)))
		return (NULL);
	ft_memmove(ret, b, n);
	return (ret);
}
