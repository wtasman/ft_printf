#include "ft_printf.h"

void ft_print1byte(int c)
{
	ft_putchar(c);
}

void ft_print2bytes(int c)
{
	ft_putchar(0xC0 + ((c & 0x07C0) >> 6));
	ft_putchar(0x80 + (c & 0x003f));
}

void ft_print3bytes(int c)
{
	ft_putchar(0xE0 + ((c & 0xF000) >> 12));
	ft_putchar(0x80 + ((c & 0xFC0) >> 6));
	ft_putchar(0x80 + (c & 0x003f));
}

void ft_print4bytes(int c)
{
	ft_putchar(0xF0 + ((c & 0x1C000) >> 18));
	ft_putchar(0x80 + ((c & 0x3F000) >> 12));
	ft_putchar(0x80 + ((c & 0xFC0) >> 6));
	ft_putchar(0x80 + (c & 0x003f));
}

void	ft_putwchar(int c)
{
	if (c <= 0x7F)
		ft_print1byte(c);
	else if (c > 0x7F && c <= 0x7FF)
		ft_print2bytes(c);
	else if (c > 0x7FF && c <= 0xFFFF)
		ft_print3bytes(c);
	else if (c > 0xFFFF && c <= 0x10FFFF )
		ft_print4bytes(c);
}