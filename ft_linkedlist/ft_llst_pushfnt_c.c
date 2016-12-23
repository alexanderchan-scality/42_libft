/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_pushfnt_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 06:28:16 by achan             #+#    #+#             */
/*   Updated: 2016/12/22 06:28:18 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"

void	ft_llst_pushfnt_c(t_llist *llst, void const *new, size_t size)
{
	t_node	*new_node;
	t_node	*head;

	if (!llst)
		return ;
	if (!(new_node = ft_node_new(new, size)))
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
