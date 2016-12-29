/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 00:23:35 by achan             #+#    #+#             */
/*   Updated: 2016/12/29 13:55:09 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vct_reserve(t_vector *vct, size_t new_cap)
{
	size_t	cur_size;
	void	*new_data;

	if (!vct)
		return ;
	if (new_cap <= vct->capacity)
		return ;
	cur_size = new_cap;
	if (!(new_data = (void *)malloc(vct->type_size * cur_size)))
		return ;
	vct->capacity = cur_size;
	ft_memmove(new_data, vct->data, vct->total_bytes);
	cur_size = (vct->capacity * vct->type_size) - vct->total_bytes;
	ft_bzero(new_data + vct->total_bytes, cur_size);
	if (vct->data)
		free(vct->data);
	vct->data = new_data;
	vct->total_bytes = vct->capacity * vct->type_size;
}
