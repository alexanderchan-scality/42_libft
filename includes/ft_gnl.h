/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:45:28 by achan             #+#    #+#             */
/*   Updated: 2017/01/25 11:46:36 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include <ft_linkedlist.h>

# define GNL_BUFF_SIZE	4096

typedef struct		s_fd_state
{
	int				fd;
	size_t			rem_size;
	char			rem[GNL_BUFF_SIZE];
}					t_fd_state;
#endif
