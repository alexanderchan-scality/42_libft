/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 11:32:07 by achan             #+#    #+#             */
/*   Updated: 2016/12/31 23:40:27 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_printf_helper.h"

/*
**	length_modifier return values:
**	return 0:	no length modifier
**	return 1:	hh	-	char
**	return 2:	h	-	short
**	return 3:	l	-	long
**	return 4:	ll	-	long long
**	return 5:	j	-	intmax_t
**	return 6:	z	-	size_t
**	return 7:	t	-	ptrdiff_t
*/
static int	print(char spec, char **str, t_fmt format, va_list args)
{
	int	length;
	int	ret;

	length = length_modifier(str);
	return (0);
}

int			ft_print_str(char spec, char **str, int pos, va_list args)
{
	t_fmt	format;
	char	*output;

	ft_bzero(&format, sizeof(format));
	flag_check(**str, &format);
	if (width_check(**str, &format))
		return (-1);
	if (precision_check(**str, &format))
		return (-1);
	return print(spec, **str, format, args);
}
