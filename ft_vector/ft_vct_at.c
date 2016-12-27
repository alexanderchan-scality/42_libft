/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 00:12:10 by achan             #+#    #+#             */
/*   Updated: 2016/12/27 02:19:11 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vct_at(t_vector *vct, size_t ind)
{
	void	*data_pos;

	if (!vct)
		return (NULL);
	if (ind >= vct->size || !vct->data)
		return (NULL);
	data_pos = vct->data + (vct->type_size * ind);
	return (data_pos);
}
