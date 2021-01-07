#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int a = 0;
	int i = ft_printf("\n<%.0p>", 0);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%.0p>", 0);
	printf("\nii = <<<< %d >>>>", j);
}
