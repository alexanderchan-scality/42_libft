/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:37:46 by achan             #+#    #+#             */
/*   Updated: 2016/12/15 12:36:22 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;
	char	*c1;
	char	*c2;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		ret->content_size = content_size;
		ret->content = (void *)malloc(content_size);
		c1 = (char *)(ret->content);
		c2 = (char *)content;
		while (content_size)
		{
			--content_size;
			c1[content_size] = c2[content_size];
		}
	}
	else
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	ret->next = NULL;
	return (ret);
}
