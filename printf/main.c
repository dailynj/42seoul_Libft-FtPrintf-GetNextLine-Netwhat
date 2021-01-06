#include "./includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("\n<%03%>");
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%03%>");
	printf("\nii = <<<< %d >>>>", j);
}
