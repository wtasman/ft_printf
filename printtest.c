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

	len = 0;
	mylen =0;
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
	len = printf("%s\n", "practice");
	mylen = ft_printf("%c\n", 'P');
	printf("len = %i\nmylen = %i\n", len, mylen);
	bi = ft_itoa_base(hex, 2);
	printf("%s\n", bi);

	return (0);
}
