#include "ft_printf.h"

int	c_spec(va_list a_list, t_mods *mods)
{
	int len;
	char	c;

	len = 0;
	if (mods->caps || mods->l)
	{
		c = va_arg(a_list, wint_t);
		ft_putwchar(c);
	}
	else
	{
		c = va_arg(a_list, int);
		write(1, &c, 1);
	}
	len++;
	return (len);
}