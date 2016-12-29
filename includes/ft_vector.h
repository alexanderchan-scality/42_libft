/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 23:11:16 by achan             #+#    #+#             */
/*   Updated: 2016/12/28 16:22:42 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ft_general.h"

typedef struct	s_vector
{
	void		*data;
	size_t		type_size;
	size_t		size;
	size_t		capacity;
	size_t		total_bytes;
}				t_vector;

t_vector		*ft_vct_blank(size_t type_size);
t_vector		*ft_vct_new(size_t size, size_t type_size);

void			ft_vct_add(t_vector *vct, void *new, size_t ins_size);

void			ft_vct_del(t_vector **vct, void (*del)());
void			ft_vct_deli(t_vector *vct, size_t ind, void (*del)());

void			*ft_vct_at(t_vector *vct, size_t ind);

int				ft_vct_empty(t_vector *vct);
size_t			ft_vct_size(t_vector *vct);
size_t			ft_vct_capacity(t_vector *vct);
size_t			ft_vct_type_size(t_vector *vct);
size_t			ft_vct_total_bytes(t_vector *vct);

void			ft_vct_reserve(t_vector *vct, size_t new_cap);
void			ft_vct_resize(t_vector *vct, size_t new_size);

#endif
