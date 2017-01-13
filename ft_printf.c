/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:31:07 by wasman            #+#    #+#             */
/*   Updated: 2017/01/09 15:02:36 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

f_list	*ft_init_flags(void)
{
	f_list *flags;

	flags = (f_list *)malloc(sizeof(f_list));
	flags->width = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->dash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->j = 0;
	flags->z = 0;
	return (flags);
}

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
		str = va_arg(a_list, void *);
	else 
		str = va_arg(a_list, void *);
	if (**ptr && is_cap(ptr) == 1)
	{
		printf("fun\n");
	}
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);	
}

int	c_spec(va_list a_list, char **ptr)
{
	int len;
	char	c;

	len = 0;
	if (*ptr && is_cap(ptr) == 1)
		c = va_arg(a_list, long int);
	else
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

int o_spec(va_list a_list, char **ptr, f_list *flags)
{
	int		len;
	char	*str;

	len = 0;
	if (flags && flags->hash)
	{
		write(1, "0", 1);
		len++;
	}
	if (flags && flags->space)
	{
		write(1, " ", 1);
		len++;
	}
	if (**ptr && is_cap(ptr) == 0)
		str = ft_itoa_base(va_arg(a_list, int), 8);
	else 
		str = ft_itoa_base(va_arg(a_list,long int), 8);
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int d_spec(va_list a_list, char **ptr, f_list *flags)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	if (flags && flags->space == 1)
	{
		len++;
		write(1, " ", 1);
	}
	if (**ptr && is_cap(ptr) == 0)
		str = ft_itoa_base(va_arg(a_list, int), 10);
	else 
		str = ft_itoa_base(va_arg(a_list,long int), 10);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	len += i;
	return (len);
}

int x_spec(va_list a_list, char **ptr, f_list *flags)
{
	int		len;
	char	*str;

	len = 0;
	if (flags && flags->space)
	{
		write(1, " ", 1);
		len++;
	}
	if (**ptr && is_cap(ptr) == 0)
		str = ft_itoa_base(va_arg(a_list, int), 16);
	else 
		str = ft_itoa_base(va_arg(a_list,long int), 16);
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	is_spec(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		   	c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

int is_flag(int c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int is_length(int c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

void	store_type(char **ptr, int *len, va_list a_list, f_list *flags)
{
	if (*ptr && (**ptr == 's' || **ptr == 'S'))
		*len += s_spec(a_list, &*ptr);
	else if (*ptr && **ptr == 'p')
		*len += p_spec(a_list);
	else if (*ptr && (**ptr == 'd' || **ptr == 'i' || **ptr == 'D'))
		*len += d_spec(a_list, &*ptr, &*flags);
	else if (*ptr && (**ptr == 'o' || **ptr == 'O'))
		*len += o_spec(a_list, &*ptr, &*flags);
	else if (*ptr && (**ptr == 'u' || **ptr == 'U'))
		*len += u_spec(a_list, &*ptr);
	else if (*ptr && (**ptr == 'x' || **ptr == 'X'))
		*len += x_spec(a_list, &*ptr, &*flags);
	else if (*ptr && (**ptr == 'c' || **ptr == 'C'))
		*len += c_spec(a_list, &*ptr);
	else if (*ptr && **ptr == '%')
		*len += double_percent();
}

void	flag_check(char **ptr, f_list *flags)
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
	else if (**ptr == ' ')
		flags->space = 1;
}

/*int		length_check(char **ptr, f_list flags)
{
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
}*/

int	print_final_format(va_list a_list, const char *format)
{
	int	len;
	f_list *flags;
	char	*ptr;

	len = 0;
	flags = ft_init_flags();
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
			if (*ptr && !is_spec(*ptr))
			{
				if (!is_flag(*ptr) && !is_length(*ptr))
					return (-1);
				while (!is_spec(*ptr) && is_flag(*ptr))
				{
					flag_check(&ptr, flags);
					ptr++;
				}
			}
			store_type(&ptr, &len, a_list, flags);
		}
		ptr++;
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

int	main(void)
{
	int len;
	int mylen;
	int ft;

	ft = 42;
	len = 0;
	mylen = 0;
	len = printf("% d%s knows his %s%c", ft, "Torrey", "stuff", '\n');
	mylen = ft_printf("% d%s knows his %s%c", ft, "Torrey", "stuff", '\n');
	printf("len = %i\nmylen = %i\n", len, mylen);
	return(0);
}