#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("\n<%04.0d>", -12);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%04.0d>", -12);
	printf("\nii = <<<< %d >>>>", j);
}
