#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 10:46:51 by mkal              #+#    #+#              #
#    Updated: 2021/01/14 11:15:24 by mkal             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
       helpers/ft_putchar_ret.c \
       helpers/ft_puts_precision.c \
       helpers/ft_str_tolower.c \
       helpers/ft_utoa_base.c \
       helpers/ft_u_itoa.c \
       helpers/ft_l_itoa.c \
       srcs/ft_handle.c \
       srcs/ft_handle_flags.c \
       srcs/ft_handle_width.c \
       srcs/ft_handle_int.c \
       srcs/ft_handle_char.c \
       srcs/ft_handle_percent.c \
       srcs/ft_handle_pointer.c \
       srcs/ft_handle_string.c \
       srcs/ft_handle_base.c \
       srcs/ft_handle_uint.c \

OBJS = ${SRCS:.c=.o} 


INCLUDES = inc

LIBFT = libft
LIBFT_NAME = libft.a
LIBFT_INC = libft/libft.h

.c.o :
	gcc -Wall -Wextra -Werror -c $< -o${<:.c=.o} -I${INCLUDES}


${NAME} : ${OBJS}
	make all -C ${LIBFT}/
	cp ${LIBFT}/${LIBFT_NAME} ${NAME}
	ar rc ${NAME} ${OBJS}

all : ${NAME}

clean : 
	rm -f ${OBJS}
	make clean -C ${LIBFT}

fclean : clean
	rm -f ${NAME}
	make fclean -C ${LIBFT}

re : fclean all

bonus : ${NAME}

.PHONY: all clean fclean re .c.o
