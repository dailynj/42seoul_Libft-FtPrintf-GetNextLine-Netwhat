# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 17:37:46 by najlee            #+#    #+#              #
#    Updated: 2020/12/22 18:24:39 by najlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	*.c
OBJS	=	$(SRCS:.c=.o)
NAME 	=	libft.a
CC		=	gcc
CF		=	-Wall -Werror -Wextra -I "libft.h"

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar -cr $(NAME) $(OBJS)

$(OBJS)	:	$(SRCS)
	$(CC) $(CF) -c $^

clean	:	
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		: fclean all clean
