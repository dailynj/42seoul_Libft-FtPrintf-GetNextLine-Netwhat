#include "printf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("<%5d>", 123);
	printf("\nft = <<<< %d >>>>", i);
	
	int j = printf("\n<%5d>", 123);
	printf("\nii = <<<< %d >>>>", j);
}
