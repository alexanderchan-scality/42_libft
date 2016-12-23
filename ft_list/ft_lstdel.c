/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:05:23 by achan             #+#    #+#             */
/*   Updated: 2016/12/15 16:13:23 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst)
		return ;
	if (!*alst)
		return ;
	while (*alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		(*del)(tmp->content, tmp->content_size);
		tmp->next = NULL;
		free(tmp);
	}
}
