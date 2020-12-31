#include "printf.h"
#include <stdio.h>

int main()
{
	int i = ft_printf("%-4c", 'c');
	printf("\nft = <<<< %d >>>>", i);
	
	i = printf("%-4c", 'c');
	printf("\nii = <<<< %d >>>>", i);
}
