#include "ft_printf.h"

int	p_spec(va_list a_list)
{
	int		len;
	int		addr;
	char	*str;

	len = 0;
	addr = (int)va_arg(a_list, void *);
	str = ft_itoa_base(addr, 16);
	ft_putstr("0x10");
	ft_putstr(str);
	len = (ft_strlen(str) + 4);
	return (len);
}