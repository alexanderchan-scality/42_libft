/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:06:17 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 15:53:43 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

t_node	*ft_node_add(void const *data, size_t data_size)
{
	t_node	*new_node;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	if (data)
	{
		new_node->data_size = data_size;
		new_node->data = (void *)data;
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
