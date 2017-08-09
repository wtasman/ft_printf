#include "ft_printf.h"

int	s_spec(va_list a_list, t_mods *mods)
{
	int len;
	char	*str;
	wchar_t *w_str;

	len = 0;

	if (mods->caps || mods->l)
	{
		w_str = va_arg(a_list, wchar_t *);
		len += ft_putwstr((int *)w_str);
	}
	else 
	{
		str = va_arg(a_list, char *);
		len += ft_strlen(str);
		ft_putstr(str);
	}
	return (len);	
}