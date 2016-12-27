/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 01:03:11 by achan             #+#    #+#             */
/*   Updated: 2016/12/27 02:15:58 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vct_add(t_vector *vct, void *new, size_t ins_size)
{
	void	*data_pos;

	if(!vct || !new)
		return ;
	if (vct->type_size != ins_size)
		return ;
	if (!vct->capacity)
		ft_vct_reserve(vct, 1);
	if ((vct->size + 1) > vct->capacity)
		ft_vct_reserve(vct, vct->capacity * 2);
	data_pos = vct->data + (vct->type_size * vct->size);
	ft_memmove(data_pos, new, ins_size);
	++(vct->size);
}
