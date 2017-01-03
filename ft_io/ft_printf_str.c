/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:13:08 by achan             #+#    #+#             */
/*   Updated: 2017/01/02 22:03:28 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_printf_helper.h"
#include "ft_printf_struct.h"

int			ft_printf_s_str(char **s, va_list arg_list,
							t_vector *segs, t_vector *args)
{
	t_fmt	*format;
	t_seg	*seg;

	if (!(format = new_fmt()) || !(seg = new_seg()))
		return (-1);
	if (spec_type_check(s, format, seg))
	flag_check(s, format);
	if (width_check(s, format, seg))
	if (precision_check(s, format, seg))
	if (length_check(s, format, seg))
}
