/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:31:27 by achan             #+#    #+#             */
/*   Updated: 2016/12/28 12:50:07 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"

void	ft_llst_del(t_llist **llst, void (*del)())
{
	t_node	*node;
	t_node	*tmp;

	if (!llst)
		return ;
	if (!*llst)
		return ;
	node = (*llst)->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		if ((*del))
			(*del)(tmp->data, tmp->data_size);
		else
			free(tmp->data);
		tmp->data = NULL;
		free(tmp);
	}
	(*llst)->head = NULL;
	(*llst)->tail = NULL;
	free(*llst);
	*llst = NULL;
}
