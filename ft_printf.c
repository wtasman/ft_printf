/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:31:07 by wasman            #+#    #+#             */
/*   Updated: 2017/01/09 10:05:17 by wasman           ###   ########.fr       */
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

int	is_cap(char **ptr)
{
	return((**ptr >= 'A' && **ptr <= 'Z'));
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

int	s_spec(va_list a_list, char **ptr)
{
	int len;
	char	*str;

	len = 0;
	if (**ptr && is_cap(ptr) == 0)
	{
		str = va_arg(a_list, void *);
		printf("fun\n");
	}
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

int u_spec(va_list a_list, char **ptr)
{
	int len;
	int value;
	char	*str;

	len = 0;
	if (**ptr && is_cap(ptr) == 0)
		value = va_arg(a_list, int);
	else 
		value = va_arg(a_list, long int);
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

void	store_type(char **ptr, int *len, va_list a_list)
{
	if (*ptr && (**ptr == 's' || **ptr == 'S'))
		*len += s_spec(a_list, &*ptr);
	else if (*ptr && **ptr == 'p')
		*len += p_spec(a_list);
	else if (*ptr && (**ptr == 'd' || **ptr == 'i' || **ptr == 'D'))
		*len += number_spec(a_list, 10, &*ptr);
	else if (*ptr && (**ptr == 'o' || **ptr == 'O'))
		*len += number_spec(a_list, 8, &*ptr);
	else if (*ptr && (**ptr == 'u' || **ptr == 'U'))
		*len += u_spec(a_list, &*ptr);
	else if (*ptr && (**ptr == 'x' || **ptr == 'X'))
		*len += number_spec(a_list, 16, &*ptr);
	else if (*ptr && (**ptr == 'c' || **ptr == 'C'))
		*len += c_spec(a_list, &*ptr);
	else if (*ptr && **ptr == '%')
		*len += double_percent()
}

int	is_spec(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		   	c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

int	flag_check(char **ptr, f_list flags)
{
	if (*ptr && **ptr == '#')
		flags->hash = 1;
	else if (*ptr && ft_isdigit(**ptr) == 1)
		flags->width = 1;
	else if (*ptr && **ptr == '0')
		flags->zero = 1;
	else if (*ptr && **ptr == '-')
		flags->dash = 1;
	else if (*ptr && **ptr == '+')
		flags->plus = 1;
	else if (*ptr && **ptr == ' ')
		flags->spac = 1;
	else if (*ptr && **ptr == 'h')
	{
		if (*ptr && ((**ptr + 1) == 'h'))
		{		
			flags->hh = 1;
			ptr++;
		}
		else
			flags->h = 1;
	}
	else if (*ptr && **ptr == 'l')
	{
		if (*ptr && ((**ptr + 1) == 'l'))
		{
			flags->ll = 1;
			ptr++;
		}
		else
			flags->l = 1;
	}
	else if (*ptr && **ptr == 'j')
		flags->j = 1;
	else if (*ptr && **ptr == 'z')
		flags->z = 1;
	else
		return (0);
	return (1);
}

int	print_final_format(va_list a_list, const char *format)
{
	int	len;
	f_list *flags;
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
			if (*ptr && is_spec(*ptr) == 0)
			{
				while (is_spec(*ptr) == 0)
				{
					//printf("works inside if\n");
					if (flag_check(&ptr, flags) == 0)
						return (-1);
					if (flags->hash == 1)
						printf("this shit works");
					ptr++;
				}
			}
			//printf("works here\n");
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

int main(void)
{
	int len;
	int mylen;
	int ft;

	ft = 42;
	len = 0;
	mylen = 0;
	len = printf("%d%s knows his %s%c", ft, "Torrey", "stuff", '\n');
	mylen = ft_printf("%d%#s knows his %s%c", ft, "Torrey", "stuff", '\n');
	printf("len = %i\nmylen = %i\n", len, mylen);
	return(0);
}
