/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 23:29:08 by achan             #+#    #+#             */
/*   Updated: 2017/01/04 20:25:21 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

t_fmt	*new_fmt(void)
{
	t_fmt	*new;

	if (!(new = (t_fmt *)malloc(sizeof(t_fmt))))
		return (NULL);
	ft_bzero(new, sizeof(t_fmt));
	new->f_spec_type = SPEC_UNSET;
	new->f_w_type = WP_UNSET;
	new->f_p_type = WP_UNSET;
	return (new);
}

t_seg	*new_seg(void)
{
	t_seg	*new;

	if (!(new = (t_seg *)malloc(sizeof(t_seg))))
		return (NULL);
	new->str = NULL;
	new->fmt = NULL;
	return (new);
}

void	seg_del(t_seg *seg)
{
	if (!seg)
		return ;
	if (seg->str)
		free(seg->str);
	if (seg->fmt)
		free(seg->fmt);
}
