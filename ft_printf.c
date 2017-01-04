/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:31:07 by wasman            #+#    #+#             */
/*   Updated: 2017/01/04 13:36:37 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	double_percent(void)
{
	int len;

	len = 0;
	write(1, "%", 1);
	len++;
	return (len);
}

int	number_spec(va_list a_list, int  base)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa_base(va_arg(a_list, int), base);
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	s_spec(va_list a_list)
{
	int len;
	char	*str;

	len = 0;
	str = va_arg(a_list, void *);
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
	
}

int	c_spec(va_list a_list)
{
	int len;
	char	c;

	len = 0;
	c = va_arg(a_list, int);
	write(1, &c, 1);
	len++;
	return (len);
}

int u_spec(va_list a_list)
{
	int len;
	int value;
	char	*str;

	len = 0;
	value = va_arg(a_list, int);
	value = (unsigned int)value;
	str = ft_itoa_base(value, 10);
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return(len);
}

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

int space_flag(char **ptr)
{
	int len;

	len = 0;
	write(1, " ", 1);
	len++;
	while (**ptr == ' ')
		ptr++;
	return (len);
}

void	store_type(char **ptr,int *len, va_list a_list)
{
	if (*ptr && (**ptr == 's'))
		*len += s_spec(a_list);
	else if (*ptr && **ptr == 'p')
		*len += p_spec(a_list);
	else if (*ptr && (**ptr == 'd' || **ptr == 'i'))
		*len += number_spec(a_list, 10);
	else if (*ptr && **ptr == 'o')
		*len += number_spec(a_list, 8);
	else if (*ptr && **ptr == 'u')
		*len += u_spec(a_list);
	else if (*ptr && **ptr == 'x')
		*len += number_spec(a_list, 16);
	else if (*ptr && **ptr == 'c')
		*len += c_spec(a_list);
	else if (*ptr && **ptr == '%')
		*len += double_percent();
}

int	print_final_format(va_list a_list, const char *format)
{
	int	len;
	char	*ptr;

	len = 0;
	ptr = (char *)format;
	while (*ptr)
	{
		while (*ptr && *ptr != '%')
		{
			write(1, ptr, 1);
			len++;
			ptr++;
		}
		if (*ptr && *ptr == '%')
		{
			ptr++;
			store_type(&ptr, &len, a_list);
			ptr++;
		}
	}
	return (len);
}

int ft_printf(const char *format, ...)
{
	va_list a_list;
	int len;

	len =0;
	if (format)
	{
		va_start(a_list, format);
		len = print_final_format(a_list, format);
		va_end(a_list);
	}
	return (len);
}

/*int main(void)
{
	int len;
	int mylen;
	int ft;

	ft = 42;
	len = 0;
	mylen = 0;
	len = printf("%o%p knows his %s%c", ft, "Torrey", "stuff", '\n');
	mylen = ft_printf("%o%p knows his %s%c", ft, "Torrey", "stuff", '\n');
	printf("len = %i\nmylen = %i\n", len, mylen);
	return(0);
}*/
