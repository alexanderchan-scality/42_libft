/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_idel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:03:02 by achan             #+#    #+#             */
/*   Updated: 2016/12/22 06:25:14 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"

void	ft_llst_idel(t_llist *llst, void *id, int (*cmp)())
{
	t_node	*del_node;

	if (!llst || !id || !(*cmp))
		return ;
	if (!(del_node = ft_llst_find_n(llst, id, (*cmp))))
		return ;
	free(del_node->data);
	if (llst->head == del_node && llst->tail == del_node)
	{
		llst->head = NULL;
		llst->tail = NULL;
	}
	else if (llst->head == del_node)
		llst->head = del_node->next;
	else if (llst->tail == del_node)
		llst->tail = del_node->prev;
	ft_node_del(&del_node);
}
