/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:56:32 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 19:44:41 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"

void	*ft_llst_find(t_llist *llst, void *id, int (*cmp)())
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
			return (tmp->data);
		tmp = tmp->next;
	}
	return (NULL);
}
