# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achan <achan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 13:03:37 by achan             #+#    #+#              #
#    Updated: 2016/12/16 19:29:30 by achan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	=	../objs
CC		=	gcc
WFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	-c
GFLAGS	=	-g
IFLAGS	=	-I ../includes
C_SRCS	=	$(wildcard ft*.c)
C_OBJS	=	$(addprefix $(OBJS)/, ${C_SRCS:.c=.o})

.PHONY:		all clean fclean test re

all: $(C_OBJS)

$(C_OBJS): $(C_SRCS)
	@$(CC) $(WFLAGS) $(GFLAGS) $(IFLAGS) $(CFLAGS) $(subst $(OBJS),.,$*.c) -o $@

clean:		
	@rm -rf $(OBJS) ||:

fclean: clean
	@rm -rf libft.a ||:
	@rm -rf test ||:

re: fclean $(NAME)
