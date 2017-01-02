/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 12:58:44 by achan             #+#    #+#             */
/*   Updated: 2017/01/02 13:37:23 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helper.h"

#define FLAG(c) ((c) == '-' || (c) == '+' || (c) == ' ' || (c) == '#')
#define NUM(c)	((c) >= '0' && (c) <= '9')
#define I(c)	((c) == 'i')
#define D(c)	((c) == 'd' || (c) == 'D')
#define O(c)	((c) == 'o' || (c) == 'O')
#define U(c)	((c) == 'u' || (c) == 'U')
#define X(c)	((c) == 'x' || (c) == 'X')
#define B(c)	((c) == 'b')
#define S(c)	((c) == 's' || (c) == 'S')
#define C(c)	((c) == 'c' || (c) == 'C')
#define P(c)	((c) == 'p')

#define N(c)	((c) == 'n')
#define E(c)	((c) == 'e' || (c) == 'E')
#define F(c)	((c) == 'f' || (c) == 'F')
#define G(c)	((c) == 'g' || (c) == 'G')
#define A(c)	((c) == 'a' || (c) == 'A')

int		is_specifier(char c)
{
	return (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
			c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'b' ||
			c == 's' || c == 'S' || c == 'c' || c == 'C' || c == 'p');
}

void	flag_check(char **str, t_fmt *fmt)
{
	while (**str && (FLAG(**str) || **str == '0'))
	{
		if (**str == '-')
			fmt->f_justify = 1;
		else if (**str == '+')
			fmt->f_sign = 1;
		else if (**str == ' ')
			fmt->f_space = 1;
		else if (**str == '#')
			fmt->alt = 1;
		else if (**str == '0')
			fmt->zero = 1;
		++(*str);
	}
}

int		width_check(char **str, t_fmt *fmt)
{
	int	width;

	width = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')
		++(*str);
	if (**str == '*')
	{
		if (width > 0)
			return (1);
		fmt->f_min = -1;
	}
	return (0);
}

int		precision_check(char **str, t_fmt *fmt)
{
	int	width;

	if (**str != '.')
	{
		fmt->f_no_precision = 1;
		return (0);
	}
	++(*str);
	width = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')
		++(*str);
	if (**str == '*')
	{
		if (width > 0)
			return (1);
		fmt->f_max = -1;
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
	return (0);
}
