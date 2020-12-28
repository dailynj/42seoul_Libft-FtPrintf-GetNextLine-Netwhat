# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jongpark <jongpark@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 16:34:33 by jongpark          #+#    #+#              #
#    Updated: 2020/12/27 16:49:57 by jongpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CF			=	-Wall -Wextra -Werror -I "libft.h"
NAME		=	libft.a

SRCS		=	\
				ft_isdigit.c\
				ft_memset.c\
				ft_strlen.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memccpy.c\
				ft_memmove.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strnstr.c\
				ft_strncmp.c\
				ft_atoi.c\
				ft_isascii.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_isprint.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strtrim.c\
				ft_strjoin.c\
				ft_split.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putnbr_fd.c\
				ft_putendl_fd.c\
				ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstmap.c\
				ft_lstiter.c\
				ft_math.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

bonus		:	all

$(NAME)	:	$(OBJS)
				ar rsc $@ $^
				ranlib $@

%.o			:	%.c
				$(CC) $(CF) -c $<

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean	all

.PHONY		:	all clean fclean re
