/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:41:02 by achan             #+#    #+#             */
/*   Updated: 2016/12/16 19:50:07 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

void	ft_node_del(t_node **node)
{
	t_node	*prev;
	t_node	*next;

	if (!node)
		return ;
	if (!*node)
		return ;
	prev = (*node)->prev;
	next = (*node)->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	if (*node)
		free(*node);
	*node = NULL;
}
