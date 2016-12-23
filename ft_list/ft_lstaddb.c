/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:11:56 by achan             #+#    #+#             */
/*   Updated: 2016/12/15 12:35:21 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstaddb(t_list *alst, t_list *new)
{
	t_list	*l_tmp;

	if (!alst)
		return ;
	if (!new)
		return ;
	l_tmp = alst->next;
	alst->next = new;
	new->next = l_tmp;
}
