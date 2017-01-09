#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int len;
	int mylen;

	len = 0;
	mylen =0;
	len = printf("This is a simple test.");
	mylen = ft_printf("This is a simple test.");
	printf("len = %i\nmylen = %i\n", len, mylen);
	len = printf("This is a simple test.\nSecond sentence.\n");
	mylen = ft_printf("This is a simple test.\nSecond sentence.\n");
	printf("len = %i\nmylen = %i\n", len, mylen);
	len = printf("");
	mylen = ft_printf("");
	printf("len = %i\nmylen = %i\n", len, mylen);
	len = printf("\n");
	mylen = ft_printf("\n");
	printf("len = %i\nmylen = %i\n", len, mylen);

	return (0);
}
