/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 12:58:44 by achan             #+#    #+#             */
/*   Updated: 2017/01/05 15:06:45 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helper.h"
#include "ft_printf_struct.h"

int		is_specifier(char c)
{
	return (I(c) || D(c) || O(c) || U(c) || X(c) ||
			B(c) || S(c) || C(c) || P(c) || N(c))
}

int		spec_type_check(char **str, t_fmt *fmt, t_info *info)
{
	int		val;

	val = 0;
	while (NUM(**str))
		val = (val * 10) + (*(*str)++ - '0');
	if (val > 0)
	{
		if (**str == '$')
		{
			if (!info->arg_flag && !ft_vct_empty(info->args))
				return (1);
			info->arg_flag = 1;
			fmt->f_spec_type = val;
			++(*str);
		}
		else
		{
			fmt->f_w_type = WP_NORMAL;
			fmt->f_width = val;
		}
	}
	else
		if (**str == '$')
			return (1);
	return (0);
}

int		flag_check(char **str, t_fmt *fmt)
{
	while (**str && FLAG(**str))
	{
		if (**str == '-')
			fmt->f_justify = 1;
		else if (**str == '+')
			fmt->f_sign = 1;
		else if (**str == ' ')
			fmt->f_space = 1;
		else if (**str == '#')
			fmt->f_alt = 1;
		else if (**str == '0')
			fmt->f_zero = 1;
		else if (**str == '\'')
			fmt->f_apost = 1;
		++(*str);
	}
	return (0);
}

int		width_check(char **str, t_fmt *fmt, t_info *info)
{
	int	width;

	if (**str == '*' && ++(*str))
		fmt->f_w_type = WP_ARGVAL;
	width = 0;
	while (NUM(**str))
		width = (width * 10) + (*(*str)++ - '0');
	fmt->f_width = width;
	if (width > 0)
	{
		if (**str == '$')
		{
			if (!info->arg_flag && !ft_vct_empty(info->args))
				return (1);
			fmt->f_w_type = WP_NARGVAL;
		}
		else
		{
			if (fmt->f_w_type == WP_ARGVAL)
				return (1);
			fmt->f_w_type = WP_NORMAL;
		}
	}
	return (0);
}

int		precision_check(char **str, t_fmt *fmt, t_info *info)
{
	int	precision;

	if (**str == '*' && ++(*str))
		fmt->f_p_type = WP_ARGVAL;
	precision = 0;
	while (NUM(**str))
		precision = (precision * 10) + (*(*str)++ - '0');
	fmt->f_precision = precision;
	if (precision > 0)
	{
		if (**str == '$')
		{
			if (!info->arg_flag && !ft_vct_empty(info->args))
				return (1);
			fmt->f_p_type = WP_NARGVAL;
		}
		else
		{
			if (fmt->f_p_type == WP_ARGVAL)
				return (1);
			fmt->f_p_type = WP_NORMAL;
		}
	}
	return (0);
}

int		length_modifier(char **str)
{
	if (**str == 'h' && ++(*str))
		return ((**str == 'h' && ++(*str)) ? 1 : 2);
	else if (**str == 'l' && ++(*str))
		return ((**str == 'l' && ++(*str)) ? 4 : 3);
	else if (**str == 'j' && ++(*str))
		return (5);
	else if (**str == 'z' && ++(*str))
		return (6);
	/*else if (**str == 'L' && ++(*str))*/
		/*return (7);*/
	return (0);
}
