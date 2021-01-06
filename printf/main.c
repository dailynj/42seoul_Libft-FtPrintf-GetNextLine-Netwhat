#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("\n<%-4.4u>", 4294967295);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%03x>", 10);
	printf("\nii = <<<< %d >>>>", j);
}
