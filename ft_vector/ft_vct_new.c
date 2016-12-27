/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 23:13:27 by achan             #+#    #+#             */
/*   Updated: 2016/12/27 01:35:14 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vct_new(size_t size, size_t type_size)
{
	t_vector	*new_vct;

	if (type_size < 1)
		return (NULL);
	if (size < 1)
	{
		new_vct = ft_vct_blank(type_size);
		return (new_vct);
	}
	if (!(new_vct = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(new_vct->data = (void *)malloc(type_size * size)))
	{
		free(new_vct);
		return (NULL);
	}
	new_vct->type_size = type_size;
	new_vct->size = 0;
	new_vct->capacity = size;
	new_vct->total_bytes = type_size * size;
	ft_bzero(new_vct->data, new_vct->total_bytes);
	return (new_vct);
}
