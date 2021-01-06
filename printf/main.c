#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("\n<%-15.3s>",  NULL);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%-15.3s>",  NULL);
	printf("\nii = <<<< %d >>>>", j);
}
