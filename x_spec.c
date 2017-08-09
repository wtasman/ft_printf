#include "ft_printf.h"

int x_spec(va_list a_list, t_mods *mods)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	if (mods->hh)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 16);
	else if (mods->h)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 16);
	else if (mods->l)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned long int), 16);
	else if (mods->ll)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned long long int), 16);
	else if (mods->j)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, uintmax_t), 16);
	else if (mods->z)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, size_t), 16);
	else 
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned int), 16);
	if (mods && mods->space && !mods->plus)
	{
		write(1, " ", 1);
		len++;
	}
	if (mods && mods->hash)
	{
		if (mods->caps)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		len += 2;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		len += i;
		i++;
	}
	return (len);
}