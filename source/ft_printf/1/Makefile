NAME	=	libftprintf.a
CC		=	gcc
CF		=	-Wall -Wextra -Werror -I ./includes
SRC		=	ft_printf.c\
			ft_deal_format.c\
			ft_deal_precision.c\
			ft_deal_width.c\
			ft_deal_flag.c\
			ft_make_format.c\
			ft_make_pre_di.c\
			ft_make_pre_p.c\
			ft_format_1.c\
			ft_format_2.c\
			ft_util_printf.c
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			make all -C ./Libft
			cp ./Libft/libft.a $(NAME) 
			ar rcs $(NAME) $(OBJ)
			ranlib $(NAME)

%.o		:	%.c
			$(CC) $(CF) -c $<

clean	:
			make clean -C ./Libft
			rm -f $(OBJ)

fclean	:	clean	
			$(MAKE) -C ./Libft fclean
			rm -f $(NAME)

re		:	fclean	all
.PHONY	:	all clean fclean re
