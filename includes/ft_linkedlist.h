/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:41:11 by achan             #+#    #+#             */
/*   Updated: 2016/12/22 06:28:34 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKEDLIST_H
# define FT_LINKEDLIST_H

# include "ft_general.h"
# include "ft_node.h"

typedef struct	s_llist
{
	t_node		*head;
	t_node		*tail;
}				t_llist;

t_llist			*ft_llst_new(void);
int				ft_llst_empty(t_llist *llst);
void			ft_llst_pushfnt(t_llist *llst, void const *new, size_t size);
void			ft_llst_pushfnt_c(t_llist *llst, void const *new, size_t size);
void			ft_llst_pushbck(t_llist *llst, void const *new, size_t size);
void			ft_llst_pushbck_c(t_llist *llst, void const *new, size_t size);
void			*ft_llst_find(t_llist *llst, void *id, int (*cmp)());
t_node			*ft_llst_find_n(t_llist *llst, void *id, int (*cmp)());
void			ft_llst_del(t_llist **llst, void (*del)());
void			ft_llst_idel(t_llist *llst, void *id, int (*cmp)());

#endif
