/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:27:52 by achan             #+#    #+#             */
/*   Updated: 2016/12/15 20:29:18 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"

t_llist	*ft_llst_new(void)
{
	t_llist	*new;

	if (!(new = (t_llist *)malloc(sizeof(t_llist))))
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	return (new);
}
