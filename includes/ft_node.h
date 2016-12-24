/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 20:21:48 by achan             #+#    #+#             */
/*   Updated: 2016/12/23 16:17:56 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_H
# define FT_NODE_H

# include <stdlib.h>

typedef struct		s_node
{
	void			*data;
	size_t			data_size;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

t_node				*ft_node_add(void const *data, size_t data_size);
t_node				*ft_node_new(void const *data, size_t data_size);
void				ft_node_del(t_node **node);

#endif
