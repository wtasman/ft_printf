#include "ft_printf.h"

void ft_print1byte(wint_t c)
{
	ft_putchar(c);
}

void ft_print2bytes(wint_t c)
{
	ft_putchar(c);
	ft_putchar(c);
}

void ft_print3bytes(wint_t c)
{
	ft_putchar(c);
	ft_putchar(c);
	ft_putchar(c);
}

void ft_print4bytes(wint_t c)
{
	ft_putchar(c);
	ft_putchar(c);
	ft_putchar(c);
	ft_putchar(c);
}

void	ft_putwchar(wint_t c)
{
	if (c <= 127)
		ft_print1byte(c);
	else if (c > 127 && c <= 2047)
		ft_print2bytes(c);
	else if (c > 2047 && c <= 65535)
		ft_print3bytes(c);
	else if (c > 65535 && c <= 1114111)
		ft_print4bytes(c);
}
