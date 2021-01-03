#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("\n<%04.1d>", 198);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%04.1d>", 198);
	printf("\nii = <<<< %d >>>>", j);
}
