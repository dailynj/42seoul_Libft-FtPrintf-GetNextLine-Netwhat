NAME	=	libftprintf.a
CC		=	gcc
CF		=	-Wall -Wextra -Werror -I ./includes
SRC		=	ft_printf.c ft_fill_guide.c ft_print_result1.c \
			ft_print_result2.c ft_c.c \

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			make all -C ./libft
			cp ./libft/libft.a $(NAME) 
			ar rcs $(NAME) $(OBJ)
			ranlib $(NAME)

%.o		:	%.c
			$(CC) $(CF) -c $<

clean	:
			make clean -C ./libft
			rm -f $(OBJ)

fclean	:	clean	
			$(MAKE) -C ./libft fclean
			rm -f $(NAME)

re		:	fclean	all
.PHONY	:	all clean fclean re
