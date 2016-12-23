/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:33:07 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 16:03:11 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

t_node	*ft_node_new(void const *data, size_t data_size)
{
	t_node	*new_node;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	if (data)
	{
		new_node->data_size = data_size;
		if (!(new_node->data = (void *)malloc(data_size)))
		{
			free(new_node);
			return (NULL);
		}
		while (data_size--)
			((char *)(new_node->data))[data_size] = ((char *)data)[data_size];
	}
	else
	{
		new_node->data = NULL;
		new_node->data_size = 0;
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
