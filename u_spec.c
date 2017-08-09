#include "ft_printf.h"

int u_spec(va_list a_list, t_mods *mods)
{
	int len;
	int value;
	char	*str;

	len = 0;
	if (mods->caps)
		value = va_arg(a_list, unsigned long int);
	if (mods->hh)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 10);
	else if (mods->h)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 10);
	else if (mods->l)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned long int), 10);
	else if (mods->ll)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned long long int), 10);
	else if (mods->j)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, uintmax_t), 10);
	else if (mods->z)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, size_t), 10);
	else 
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned int), 10);
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return(len);
}