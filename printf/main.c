#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("\n<%-4.*d>",5,  -123);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%-4.*d>", 5,  -123);
	printf("\nii = <<<< %d >>>>", j);
}
