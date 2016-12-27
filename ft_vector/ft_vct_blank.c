/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 23:26:26 by achan             #+#    #+#             */
/*   Updated: 2016/12/27 01:33:12 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vct_blank(size_t type_size)
{
	t_vector	*new_vct;

	if (type_size < 1)
		return (NULL);
	if (!(new_vct = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	new_vct->data = NULL;
	new_vct->type_size = type_size;
	new_vct->size = 0;
	new_vct->capacity = 0;
	new_vct->total_bytes = 0;
	return (new_vct);
}
