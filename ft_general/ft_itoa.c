/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:10:12 by achan             #+#    #+#             */
/*   Updated: 2016/12/29 21:10:17 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

static size_t	str_size(int n)
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

char			*ft_itoa(int n)
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
		n = (n < 0) ? (n / 10) * -1 : (n / 10);
	}
	return (ret);
}
