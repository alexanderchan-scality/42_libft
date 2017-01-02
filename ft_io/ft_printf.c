/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 12:26:49 by achan             #+#    #+#             */
/*   Updated: 2017/01/02 13:37:26 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_printf_helper.h"

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
	ft_vct_add(str_seg, "", sizeof(char));
	seg->str = ft_strdup(str_seg->data);
	ft_vct_add(segs, seg, sizeof(t_seg));
	ft_vct_del(str_seg, NULL);
	free(seg);
	return ((**str) ? 1 : 0);
}

static int	ft_printf_fmt_err_chk(char *s)
{
	char	*tmp;
	int		pos;

	pos = 0;
	tmp	= *s + 1;
	while (*tmp && *tmp != '%' && !is_specifier(*tmp))
	{
		++tmp;
		++pos;
	}
	if (!*s || (*s == '%' && (!*tmp || *tmp == '%')))
		return (-1);
	return (pos);
}
static int	ft_printf_format(char **s, va_list arg_list,
								t_vector *segs, t_vector *args)
{
	int		p;
	char	spec;

	if ((p = ft_printf_fmt_err_chk(*s)) < 0)
		return (-1);
	t_vector	*str_seg;
	t_seg		*seg;

	if (!(str_seg = ft_vct_blank(sizeof(char))) || !(seg = new_seg()))
		return (-1);
	while (**s && !is_specifier(**s))
		ft_vct_add(str_seg, (*s)++, sizeof(char));
	
	t_vct_add(str_seg, "", sizeof(char));
	seg->str = ft_strdup(str_seg->data);
	ft_vct_add(segs, seg, sizeof(t_seg));
	ft_vct_del(str_seg, NULL);
	free(seg);
	/*spec = (*s)[p];*/
	/*if (C(spec) || S(spec))*/
	/*else if (D(spec) || I(spec))*/
	/*else if (B(spec) || U(spec) || X(spec) || P(spec))*/
	/*if (ret < 0)*/
		/*return (-1);*/
	return (0);
}

static int	ft_printf_err_chk(char *s, va_list arg_list,
								t_vector *segs, t_vector *args)
{
	int		i;

	while ((i = ft_printf_parse(&s, segs)))
	{
		if ((i == ft_printf_format(&s, arg_list, segs, args)) < 0)
			return (-1);
	}
	if (*s && !i)
		return (1);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list		arg_list;
	int			ret;
	t_vector	*segs;
	t_vector	*args;

	if (!format || !(segs = ft_vct_blank(sizeof(t_seg))) ||
		!(args = ft_vct_blank(sizeof(void *))))
		return (-1);
	va_start(arg_list, format);
	if (ft_printf_err_chk(format, arg_list, segs, args))
	{
		ft_vct_del(segs, &seg_del);
		ft_vct_del(args, NULL);
		return (-1);
	}
	va_end(args);
}
