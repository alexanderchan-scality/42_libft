/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 11:42:34 by achan             #+#    #+#             */
/*   Updated: 2017/01/04 20:22:26 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPER_H
# define FT_PRINTF_HELPER_H

# include <stdarg.h>
# include "ft_printf_struct.h"
# include "ft_vector.h"

#define FLAG_1(c)	((c) == '-' || (c) == '+' || (c) == ' ')
#define FLAG_2(c)	((c) == '#' || (c) == '0' || (c) == '\'')
#define FLAG(c)		(FLAG_1(c) || FLAG_2(c))
#define NUM(c)		((c) >= '0' && (c) <= '9')
#define I(c)		((c) == 'i')
#define D(c)		((c) == 'd' || (c) == 'D')
#define O(c)		((c) == 'o' || (c) == 'O')
#define U(c)		((c) == 'u' || (c) == 'U')
#define X(c)		((c) == 'x' || (c) == 'X')
#define B(c)		((c) == 'b')
#define S(c)		((c) == 's' || (c) == 'S')
#define C(c)		((c) == 'c' || (c) == 'C')
#define P(c)		((c) == 'p')
#define N(c)		((c) == 'n')

#define E(c)		((c) == 'e' || (c) == 'E')
#define F(c)		((c) == 'f' || (c) == 'F')
#define G(c)		((c) == 'g' || (c) == 'G')
#define A(c)		((c) == 'a' || (c) == 'A')

int					is_specifier(char c);

int					ft_printf_s_str(char **s, va_list arg_list,
									t_vector *segs, t_vector *args);
#endif
