/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 00:48:15 by achan             #+#    #+#             */
/*   Updated: 2016/12/27 01:36:03 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vct_resize(t_vector *vct, size_t new_size)
{
	size_t	d_size;
	void	*data_pos;

	if (!vct)
		return ;
	if (new_size == vct->size)
		return ;
	if (new_size < vct->size)
	{
		d_size = vct->total_bytes - (vct->type_size * new_size);
		data_pos = vct->data + d_size;
		ft_bzero(data_pos, d_size);
		vct->size = new_size;
		return ;
	}
	if (!(data_pos = (void *)malloc(vct->type_size)))
		return ;
	ft_bzero(data_pos, vct->type_size);
	while (new_size > vct->size)
		ft_vct_add(vct, data_pos, vct->type_size);
	free(data_pos);
}
