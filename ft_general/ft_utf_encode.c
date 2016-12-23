/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf_encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 03:54:58 by achan             #+#    #+#             */
/*   Updated: 2016/12/22 04:34:08 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

int		ft_utf_encode(int c, int *output)
{
	static unsigned char	a[5] = { 0x00, 0xFF, 0x1F, 0x0F, 0x07 };
	static unsigned char	o[5] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0 };
	unsigned char			ret;
	unsigned int			i;

	ret = (c > 0x7F) ? 2 : 1;
	ret = (c > 0x7FF) ? 3 : ret;
	ret = (c > 0xFFFF) ? 4 : ret;
	ret = (c > 0x10FFFF) ? 0 : ret;
	i = 0;
	*output = 0;
	while (i < ret)
	{
		if (i == ret - 1)
			*output |= (o[ret] | (c & a[ret])) << (8 * (ret - (i + 1)));
		else
		{
			*output |= (0x80 | (c & 0x3F)) << (8 * (ret - (i + 1)));
			c = c >> 6;
		}
		i++;
	}
	return (ret);
}
