/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 11:42:34 by achan             #+#    #+#             */
/*   Updated: 2016/12/31 17:31:30 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPER_H
# define FT_PRINTF_HELPER_H

# include <stdarg.h>

typedef struct		s_fmt
{
	int				f_justify;
	int				f_sign;
	int				f_space;
	int				f_alt;
	int				f_zero;
	int				f_min;
	int				f_no_precision;
	int				f_max;
}					t_fmt;

int					is_specifier(char c);
int					ft_print_str(char s, char **fmt, int pos, va_list args);
int					ft_print_num(char s, char **fmt, int pos, va_list args);
int					ft_print_num_b(char s, char **fmt, int pos, va_list args);

#endif
