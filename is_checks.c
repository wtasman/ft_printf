#include "ft_printf.h"

int	is_cap(int c)
{
	return((c >= 'A' && c <= 'Z'));
}

int	is_spec(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		   	c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%');
}

int is_flag(int c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int is_length(int c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}