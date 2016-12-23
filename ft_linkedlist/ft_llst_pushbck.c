/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_pushbck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:52:19 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 22:55:39 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"

void	ft_llst_pushbck(t_llist *llst, void const *new, size_t size)
{
	t_node	*new_node;
	t_node	*tail;

	if (!llst)
		return ;
	if (!(new_node = ft_node_add(new, size)))
		return ;
	if (ft_llst_empty(llst))
	{
		llst->head = new_node;
		llst->tail = new_node;
		return ;
	}
	tail = llst->tail;
	llst->tail = new_node;
	new_node->prev = tail;
	tail->next = new_node;
}
