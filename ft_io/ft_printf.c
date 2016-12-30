/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 03:09:29 by achan             #+#    #+#             */
/*   Updated: 2016/12/30 11:31:48 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static int	is_specifier(char c)
{
	return (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
			c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'b' ||
			c == 's' || c == 'S' || c == 'c' || c == 'C' || c == 'p');
}

static int	ft_printf_parse(char **str, int	*spec_pos, int *cnt)
{
	char	*tmp;

	while (**str)
	{
		if (**str == '%')
		{
			if (*(*str + 1) == '%')
				++(*str);
			else
				break;
		}
		write(1, (*str)++, 1);
		++(*cnt);
	}
	tmp = (**str) ? *str + 1 : *str;
	while (**str && *tmp && *tmp != '%' && !is_specifier(*tmp))
	{
		++tmp;
		++(*spec_pos);
	}
	if (!**str || (**str == '%' && (!*tmp || *tmp == '%')))
		return (0);
	return (1);
}

static int	ft_printf_format(char **format, int pos, va_list args)
{
	int		ret;

	if (s[p] == 'c' || s[p] == 'C' || s[p] == 's' || s[p] == 'S')
		ret = ft_print_str(format, pos, args);
	else if (s[p] == 'd' || s[p] == 'D' || s[p] == 'i' ||
				s[p] == 'u' || s[p] == 'U')
		ret = ft_print_num(format, pos, args);
	else if (s[p] == 'b' || s[p] == 'o' || s[p] == 'O' ||
				s[p] == 'x' || s[p] == 'X')
		ret = ft_print_num_b(format, pos, args);
	if (ret < 0)
		return (-1);
	return (ret);
}

static int	ft_printf_print(char *s, va_list args)
{
	int		i;
	int		p;
	int		cnt;

	cnt = 0;
	p = 0;
	while ((i = ft_printf_parse(&s, &p, &cnt)))
	{
		(*s == '%') ? ++s : s;
		if ((i = ft_printf_format(&s, p, args)) < 0)
			return (-1);
		cnt += i;
		p = 0;
	}
	if (*s && !i)
		return (-1);
	return (cnt);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	if (!format)
		return (-1);
	va_start(args, format);
	if ((ret = ft_printf_print((char *)format, args)) < 0)
		return (-1);
	va_end(args);
	return (ret);
}
