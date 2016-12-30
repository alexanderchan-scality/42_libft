/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:29:31 by achan             #+#    #+#             */
/*   Updated: 2016/12/29 22:55:40 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

static size_t	str_size(int n, size_t b)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		++i;
		n /= b;
		n = (n < 0) ? -n : n;
	}
	return (i);
}

char			*ft_itoa_b(int n, size_t b)
{
	static char	val[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
							'8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	char		*ret;
	size_t		i;
	int			rem;

	if (b == 10 || b < 2)
		return (ft_itoa(n));
	i = str_size(n, b);
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i] = 0;
	if (n == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	while (n)
	{
		rem = (n < 0) ? (n % b) * -1 : (n % b);
		ret[--i] = val[rem];
		n /= b;
		n = (n < 0) ? -n : n;
	}
	return (ret);
}
