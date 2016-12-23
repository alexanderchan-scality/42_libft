/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:01:47 by achan             #+#    #+#             */
/*   Updated: 2016/12/22 06:20:08 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

static int	is_white(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\r' || c == '\f' || c == '\v');
}

int			ft_atoi(char const *s)
{
	int		neg;
	long	ret;

	ret = 0;
	neg = 0;
	while (is_white(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg = 1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		ret *= 10;
		ret += *s++ - '0';
	}
	return (neg ? -(ret) : ret);
}
