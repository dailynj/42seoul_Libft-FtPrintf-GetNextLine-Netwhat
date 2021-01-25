# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 17:37:46 by najlee            #+#    #+#              #
#    Updated: 2020/12/27 17:23:15 by najlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c 	ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
			\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c

BN_SRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJS	=	$(SRCS:.c=.o)
BN_OBJS	=	$(BN_SRCS:.c=.o)

NAME 	=	libft.a
CC		=	gcc
CF		=	-Wall -Werror -Wextra -I "libft.h"

all		:	$(NAME)

bonus	:	$(BN_OBJS) $(NAME)
			ar -cr $(NAME) $(BN_OBJS)

$(NAME)	:	$(OBJS)
			ar -cr $(NAME) $(OBJS)

$(OBJS)	:	$(SRCS)
	$(CC) $(CF) -c $^

$(BN_OBJS)	:	$(BN_SRCS)
	$(CC) $(CF) -c $^

clean	:	
			rm -f $(OBJS) $(BN_OBJS)

fclean	:	clean
			rm -f $(NAME)

re		: fclean all clean

.PHONY	:	all clean fclean re
