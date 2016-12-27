/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 23:31:02 by achan             #+#    #+#             */
/*   Updated: 2016/12/27 02:28:51 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vct_del(t_vector **vct, void (*del)())
{
	void	*data_pos;
	size_t	ind;

	if (!vct)
		return ;
	if (!*vct)
		return ;
	if ((*vct)->data)
	{
		ind = 0;
		
		if ((*del))
		{
			while (ind < (*vct)->size)
			{
				data_pos = (*vct)->data + ((*vct)->type_size * ind);
					(*del)(data_pos);
				++ind;
			}
		}
		free((*vct)->data);
		(*vct)->data = NULL;
	}
	free(*vct);
	*vct = NULL;
}
