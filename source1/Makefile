# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suko <suko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 16:33:48 by suko              #+#    #+#              #
#    Updated: 2020/12/27 15:50:27 by suko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	 ft_putchar_fd.c ft_putstr_fd.c ft_memset.c ft_bzero.c ft_memcpy.c\
	 ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c\
	 ft_strlcat.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_strdup.c\
	 ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
	 ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
	 ft_tolower.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS=$(SRCS:.c=.o)

CC=gcc
LIBC=ar
FLAGS=-Wall -Wextra -Werror
INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) libft.h
	$(CC) -c $(FLAGS) -I $(INCLUDES) $(SRCS)
	$(LIBC) -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
