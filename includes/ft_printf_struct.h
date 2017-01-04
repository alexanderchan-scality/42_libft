/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 23:22:13 by achan             #+#    #+#             */
/*   Updated: 2017/01/03 20:08:28 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

# include "ft_general.h"

/*
**	SPECIDIER TYPE
*/
# define SPEC_NORMAL	0
# define SPEC_ARGVAL	1

/*
**	WIDTH TYPE / PRECISION TYPE
*/
# define WP_NORMAL		0
# define WP_ARGVAL		1
# define WP_NARGVAL		2

typedef struct		s_fmt
{
	char			f_spec;
	int				f_spec_type;
	int				f_justify;
	int				f_sign;
	int				f_space;
	int				f_alt;
	int				f_zero;
	int				f_w_type;
	int				f_width;
	int				f_p_type;
	int				f_precision;
	int				f_length;
}					t_fmt;

typedef struct		s_seg
{
	char			*str;
	t_fmt			*fmt;
}					t_seg;

t_fmt	*new_fmt(void);
t_seg	*new_seg(void);
void	seg_del(t_seg *seg);
#endif
