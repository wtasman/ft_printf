#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "en_US.utf8");
	int len;
	int mylen;
	int	hex;
	char	*bi;
	int	wcharstr[] = {0x1F635, '\0'};

	len = 0;
	mylen = 0;
	hex = 0x4e3e;
	len = printf("Can you say WTF\n");
	mylen = ft_printf("Can you say WTF\n");
	printf("len = %i\nmylen = %i\n", len, mylen);
	len = printf("This is a simple test.\n");
	mylen = ft_printf("This is a simple test.\n");
	printf("len = %i\nmylen = %i\n", len, mylen);
	len = printf("");
	mylen = ft_printf("");
	printf("len = %i\nmylen = %i\n", len, mylen);
	len = printf("\n");
	mylen = ft_printf("\n");
	printf("len = %i\nmylen = %i\n", len, mylen);
	len = printf("%C\n", 0x1F635);
	mylen = ft_printf("%C\n", 0x1F635);
	printf("len = %i\nmylen = %i\n", len, mylen);
	//bi = ft_itoa_base(hex, 2);
	//printf("%s\n", bi);
	//len = printf("%S\n", wcharstr);
	//mylen = ft_printf("%S\n", wcharstr);
	printf("len = %i\nmylen = %i\n", len, mylen);

	return (0);
}
