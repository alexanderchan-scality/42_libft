/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_deli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 23:41:17 by achan             #+#    #+#             */
/*   Updated: 2016/12/27 01:55:45 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vct_deli(t_vector *vct, size_t ind, void(*del)())
{
	void	*data_pos;
	size_t	d_size;

	if (!vct)
		return ;
	if (!vct->data || ind >= vct->size)
		return ;
	data_pos = vct->data + (vct->type_size * ind);
	d_size = vct->total_bytes - (vct->type_size * (ind + 1));
	if ((*del))
		(*del)(data_pos);
	ft_bzero(data_pos, vct->type_size);
	ft_memmove(data_pos, (data_pos + vct->type_size), d_size);
	data_pos = vct->data + (vct->type_size * vct->size - 1);
	ft_bzero(data_pos, vct->type_size);
	--(vct->size);
}
