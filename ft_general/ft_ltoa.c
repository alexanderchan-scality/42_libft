/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:47:14 by achan             #+#    #+#             */
/*   Updated: 2016/12/29 22:50:55 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

static size_t	str_size(long long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++i;
	while (n)
	{
		++i;
		n /= 10;
		n = (n < 0) ? -n : n;
	}
	return (i);
}

char			*ft_ltoa(long long n)
{
	char	*ret;
	size_t	i;
	int		rem;

	i = str_size(n);
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i] = 0;
	if (n == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		rem = (n < 0) ? (n % 10) * -1 : (n % 10);
		ret[--i] = rem + '0';
		n /= 10;
		n = (n < 0) ? -n : n;
	}
	return (ret);
}
