/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:13:08 by achan             #+#    #+#             */
/*   Updated: 2017/01/04 21:15:15 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_printf_helper.h"
#include "ft_printf_struct.h"

int			safe_exit(t_fmt **format, t_seg **seg)
{
	if (format)
	{
		if (*format)
		{
			free(format);
			*format = NULL;
		}
	}
	if (seg)
	{
		if (*seg)
		{
			free(seg);
			*seg = NULL;
		}
	}
	return (-1);
}

int			ft_printf_s_str(char **s, va_list arg_list, t_info *info)
{
	t_fmt	*format;
	t_seg	*seg;

	if (!(format = new_fmt()) || !(seg = new_seg()))
		return (safe_exit(&format, &seg));
	if (**s >= '1' && **s <= '9')
		if (spec_type_check(s, format, info))
			return (safe_exit(&format, &seg));
	else
		format->f_spec_type = SPEC_NORMAL;
	if (format->f_w_type > 0 || flag_check(s, format, info))
		return (safe_exit(&format, &seg));
	if (width_check(s, format, info))
			return (safe_exit(&format, &seg));
	if (**s == '.' && ++(*s))
		if (precision_check(s, format, info))
				return (safe_exit(&format, &seg));
	format->length = length_check(s, format, info);
	if (!is_specifier(**s))
		return (-1);
	format->f_spec = **s;
	seg->fmt = format;
	return (0);
}
