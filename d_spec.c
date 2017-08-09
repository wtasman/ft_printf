#include "ft_printf.h"

int d_spec(va_list a_list, t_mods *mods)
{
	int				len;
	long long		temp;
	int				i;
	char			*str;

	len = 0;
	i = 0;
	temp = 0;
	if (mods->hh)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 10);
	else if (mods->h)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 10);
	else if (mods->l)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, long int), 10);
	else if (mods->ll)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, long long int), 10);
	else if (mods->j)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, intmax_t), 10);
	else if (mods->z)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, size_t), 10);
	else 
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 10);
	if (temp > 0)
	{
		if (mods && mods->space && !mods->plus)
		{
			len++;
			write(1, " ", 1);
		}
		if (mods && mods->plus)
		{
			len++;
			write(1, "+", 1);
		}
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	len += i;
	return (len);
}