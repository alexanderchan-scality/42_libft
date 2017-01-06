/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 12:26:49 by achan             #+#    #+#             */
/*   Updated: 2017/01/05 15:23:16 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_printf_helper.h"
#include "ft_printf_struct.h"

static int	ft_printf_parse(char **s, t_vector *segs)
{
	t_vector	*str_seg;
	t_seg		*seg;

	if (!(str_seg = ft_vct_blank(sizeof(char))) || !(seg = new_seg()))
		return (-1);
	while (**s)
	{
		if (**s == '%' && ++(*s))
			if (**s != '%')
				break;
		ft_vct_add(str_seg, (*s)++, sizeof(char));
	}
	if (!ft_vct_empty(str_seg))
	{
		ft_vct_add(str_seg, "", sizeof(char));
		seg->str = ft_strdup(str_seg->data);
		ft_vct_add(segs, seg, sizeof(t_seg));
	}
	ft_vct_del(&str_seg, NULL);
	free(seg);
	return ((**s) ? 1 : 0);
}

static int	ft_printf_fmt_err_chk(char *s)
{
	char	*tmp;
	int		pos;

	pos = 0;
	tmp	= (*s) ? s + 1 : s;
	while (*tmp && *tmp != '%' && !is_specifier(*tmp))
	{
		++tmp;
		++pos;
	}
	if (!*s || (*s == '%' && (!*tmp || *tmp == '%')))
		return (-1);
	return (pos);
}

static int	ft_printf_format(char **s, va_list arg_list, t_info *info)
{
	int		p;
	int		ret;
	char	spec;

	ft_vct_empty(args);
	if ((p = ft_printf_fmt_err_chk(*s)) < 0)
		return (-1);
	*s = (**s == '%') ? ++(*s) : *s;
	spec = (*s)[p];
	if (C(spec) || S(spec))
		ret = ft_printf_s_str(s, arg_list, info);
	/*else if (D(spec) || I(spec))*/
		/*ft_printf_str(s, arg_list, segs, args);*/
	/*else if (B(spec) || U(spec) || X(spec) || P(spec))*/
		/*ft_printf_str(s, arg_list, segs, args);*/
	/*else if (E(spec) || F(spec) || G(spec) || A(spec))*/
		/*ft_printf_str(s, arg_list, segs, args);*/
	/*else if (N(spec))*/
		/*ft_printf_str(s, arg_list, segs, args);*/
	if (ret < 0)
		return (-1);
	return (0);
}

static int	ft_printf_err_chk(char *s, va_list arg_list, t_info *info)
{
	int		i;

	while ((i = ft_printf_parse(&s, info->segs)))
	{
		if ((i = ft_printf_format(&s, arg_list, info)) < 0)
			return (-1);
	}
	if (*s && !i)
		return (1);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list			arg_list;
	static t_info	str_info = {0, NULL, NULL};
	/*int			ret;*/

	str_info.arg_flag = 0;
	if (ft_printf_spec_check((char *)format))
		return (-1);
	if (!format || !(str_info.segs = ft_vct_blank(sizeof(t_seg))) ||
		!(str_info.args = ft_vct_blank(sizeof(void *))))
		return (-1);
	va_start(arg_list, format);
	if (ft_printf_err_chk((char *)format, arg_list, &str_info))
	{
		ft_vct_del(&(str_info.segs), &seg_del);
		ft_vct_del(&(str_info.args), NULL);
		return (-1);
	}
	va_end(arg_list);
	ft_vct_del(&(str_info.segs), &seg_del);
	ft_vct_del(&(str_info.args), NULL);
	return (0);
}
