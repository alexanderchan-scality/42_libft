/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:10:12 by achan             #+#    #+#             */
/*   Updated: 2016/12/18 00:34:18 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

static unsigned int	str_size(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++i;
	while (n)
	{
		++i;
		n /= 10;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char			*ret;
	unsigned int	i;
	unsigned int	neg;

	neg = 0;
	i = str_size(n);
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i] = 0;
	if (n == -2147483648)
	{
		n = -214748364;
		ret[--i] = '8';
	}
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (i)
	{
		--i;
		ret[i] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		ret[i] = '-';
	return (ret);
}
