#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int a = 0;
	int i = ft_printf("\n<%0*.*d>", 3, 4, -2147483648);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%0*.*d>", 3, 4, -2147483648);
	printf("\nii = <<<< %d >>>>", j);
}
