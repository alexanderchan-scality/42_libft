/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:13:08 by achan             #+#    #+#             */
/*   Updated: 2017/01/05 15:15:15 by achan            ###   ########.fr       */
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

static int	ft_printf_set(va_list arg_list, t_info *info,
							t_fmt *fmt, t_seg **seg)
{
	char	spec;
	void	*data;
	int		length;

	spec = fmt->f_spec;
	length = fmt->f_length;
	ft_vct_add(info->segs, seg);
	if (fmt->f_w_type == WP_ARGVAL)
	{
		data = va_arg(arg_list, void *);
		ft_vct_add(info->args, data, );
	}
	free(*seg);
	*seg = NULL;
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
	if (FLAG(**s))
		if (!(format->f_w_type == WP_UNSET) || flag_check(s, format))
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
	ft_printf_set(arg_list, info, format, &seg);
	return (0);
}
