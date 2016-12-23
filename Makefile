# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achan <achan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 13:03:37 by achan             #+#    #+#              #
#    Updated: 2016/12/22 06:06:35 by achan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	=	objs
CC		=	gcc
WFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	-c
GFLAGS	=	-g
IFLAGS	=	-I ./includes
C_SRCS	=	$(wildcard ./ft_general/ft*.c)\
			$(wildcard ./ft_io/ft*.c)\
			$(wildcard ./ft_list/ft*.c)\
			$(wildcard ./ft_node/ft*.c)\
			$(wildcard ./ft_linkedlist/ft*.c)
C_OBJS	=	$(addprefix $(OBJS)/,$(notdir ${C_SRCS:.c=.o}))
NAME	=	libft.a

.PHONY:		all clean fclean test re

all: $(NAME)

$(NAME): $(C_SRCS)
	@mkdir -p $(OBJS) ||:
	@echo "Compiling ft_general files:"
	@$(MAKE) -C ./ft_general
	@echo "Compiling ft_io files:"
	@$(MAKE) -C ./ft_io
	@echo "Compiling ft_list files:"
	@$(MAKE) -C ./ft_list
	@echo "Compiling ft_node files:"
	@$(MAKE) -C ./ft_node
	@echo "Compiling ft_linkedlist files:"
	@$(MAKE) -C ./ft_linkedlist
	@echo "libft.a created" ||:
	@ar rcs $@ $(C_OBJS)||:
	@ranlib $@ ||:

clean:
	@rm -rf $(OBJS) ||:

fclean: clean
	@rm -rf libft.a ||:
	@rm -rf test ||:

re: fclean $(NAME)
