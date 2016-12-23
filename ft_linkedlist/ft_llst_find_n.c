/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_find_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:45:53 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 19:49:40 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"

t_node	*ft_llst_find_n(t_llist *llst, void *id, int (*cmp)())
{
	t_node	*tmp;

	if (!llst || !id || !(*cmp))
		return (NULL);
	if (ft_llst_empty(llst))
		return (NULL);
	tmp = llst->head;
	while (tmp)
	{
		if ((*cmp)(tmp->data, id))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
