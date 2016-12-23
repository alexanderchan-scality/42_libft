/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:14:42 by achan             #+#    #+#             */
/*   Updated: 2016/12/15 12:35:47 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static	void	del_it(t_list *ret)
{
	t_list	*tmp;

	while (ret)
	{
		tmp = ret;
		ret = ret->next;
		if (tmp->content)
			free(tmp->content);
		tmp->next = NULL;
		free(tmp);
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(ret = (*f)(lst)))
		return (NULL);
	tmp = ret;
	while ((lst = lst->next))
	{
		if (!(tmp->next = (*f)(lst)))
		{
			del_it(ret);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (ret);
}
