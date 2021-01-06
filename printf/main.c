#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("\n<%03x>", 10);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%03x>", 10);
	printf("\nii = <<<< %d >>>>", j);
	printf("pppppppp<%s>", ft_make_d_to_x(256));
}
