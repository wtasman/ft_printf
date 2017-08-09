#include "ft_printf.h"

int o_spec(va_list a_list, t_mods *mods)
{
	int		len;
	int		i;
	char	*str;
	unsigned int temp;

	len = 0;
	i = 0;
	temp = 0;
	if (mods->hh)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 8);
	else if (mods->h)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, int), 8);
	else if (mods->l)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned long int), 8);
	else if (mods->ll)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned long long int), 8);
	else if (mods->j)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, uintmax_t), 8);
	else if (mods->z)
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, size_t), 8);
	else 
		str = ft_itoa_base((unsigned long long int)va_arg(a_list, unsigned int), 8);
	if (mods && mods->hash)
	{
		write(1, "0", 1);
		len++;
	}
	if (mods && mods->space && !mods->plus)
	{
		write(1, " ", 1);
		len++;
	}
	while (str[i])
	{
		len += i;
		write(1, &str[i], 1);
		i++;
	}
	return (len);
}