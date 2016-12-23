/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_pushfnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:30:47 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 15:09:41 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"

void	ft_llst_pushfnt(t_llist *llst, void const *new, size_t size)
{
	t_node	*new_node;
	t_node	*head;

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
	head = llst->head;
	llst->head = new_node;
	new_node->next = head;
	head->prev = new_node;
}
