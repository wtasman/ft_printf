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

t_flags	*ft_init_flags(void)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->width = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->dash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->caps = 0;
	return (flags);
}

t_lmods	*ft_init_lmods(void)
{
	t_lmods *lmods;

	lmods = (t_lmods *)malloc(sizeof(t_lmods));
	lmods->hh = 0;
	lmods->h = 0;
	lmods->l = 0;
	lmods->ll = 0;
	lmods->j = 0;
	lmods->z = 0;
	return (lmods);
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

int	s_spec(va_list a_list, t_flags *flags, t_lmods *lmods)
{
	int len;
	char	*str;

	len = 0;

	if (flags->caps || lmods->l)
	{
		str = va_arg(a_list, wchar_t *);
		len += ft_putwstr((int *)str);
	}
	else 
	{
		str = va_arg(a_list, char *);
		len += ft_strlen(str);
		ft_putstr(str);
	}
	return (len);	
}

int	c_spec(va_list a_list, t_flags *flags, t_lmods *lmods)
{
	int len;
	char	c;

	len = 0;
	if (flags->caps || lmods->l)
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

int u_spec(va_list a_list, t_flags *flags, t_lmods *lmods)
{
	int len;
	int value;
	char	*str;

	len = 0;
	if (**ptr && is_cap(ptr))
		value = va_arg(a_list, unsigned long int);
	if (**ptr && lmods->hh)
		str = ft_itoa_base(va_arg(a_list, unsigned char), 10);
	else if (**ptr && lmods->h)
		str = ft_itoa_base(va_arg(a_list, unsigned short int), 10);
	else if (**ptr && lmods->l)
		str = ft_itoa_base(va_arg(a_list, unsigned long int), 10);
	else if (**ptr && lmods->ll)
		str = ft_itoa_base(va_arg(a_list, unsigned long long int), 10);
	else if (**ptr && lmods->j)
		str = ft_itoa_base(va_arg(a_list, uintmax_t), 10);
	else if (**ptr && lmods->z)
		str = ft_itoa_base(va_arg(a_list, size_t), 10);
	else 
		str = ft_itoa_base(va_arg(a_list, unsigned int), 10);
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return(len);
}

int	p_spec(va_list a_list, t_flags *flags)
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

int o_spec(va_list a_list, t_flags *flags, t_lmods *lmods)
{
	int		len;
	int		i;
	char	*str;
	unsigned int temp;

	len = 0;
	i = 0;
	if (**ptr && lmods->hh)
		str = ft_itoa_base(va_arg(a_list, unsigned char), 8);
	else if (**ptr && lmods->h)
		str = ft_itoa_base(va_arg(a_list, unsigned short int), 8);
	else if (**ptr && lmods->l)
		str = ft_itoa_base(va_arg(a_list, unsigned long int), 8);
	else if (**ptr && lmods->ll)
		str = ft_itoa_base(va_arg(a_list, unsigned long long int), 8);
	else if (**ptr && lmods->j)
		str = ft_itoa_base(va_arg(a_list, uintmax_t), 8);
	else if (**ptr && lmods->z)
		str = ft_itoa_base(va_arg(a_list, size_t), 8);
	else 
		str = ft_itoa_base(va_arg(a_list, unsigned int), 8);
	if (flags && flags->hash)
	{
		write(1, "0", 1);
		len++;
	}
	if (flags && flags->space && !flags->plus)
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

int d_spec(va_list a_list, t_flags *flags, t_lmods *lmods)
{
	int				len;
	long long		temp;
	int				i;
	char			*str;

	len = 0;
	i = 0;
	if (**ptr && lmods->hh)
		str = ft_itoa_base(va_arg(a_list, signed char), 10);
	else if (**ptr && lmods->h)
		str = ft_itoa_base(va_arg(a_list, short int), 10);
	else if (**ptr && lmods->l)
		str = ft_itoa_base(va_arg(a_list, long int), 10);
	else if (**ptr && lmods->ll)
		str = ft_itoa_base(va_arg(a_list, long long int), 10);
	else if (**ptr && lmods->j)
		str = ft_itoa_base(va_arg(a_list, intmax_t), 10);
	else if (**ptr && lmods->z)
		str = ft_itoa_base(va_arg(a_list, size_t), 10);
	else 
		str = ft_itoa_base(va_arg(a_list, int), 10);
	if (temp > 0)
	{
		if (flags && flags->space && !flags->plus)
		{
			len++;
			write(1, " ", 1);
		}
		if (flags && flags->plus)
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

int x_spec(va_list a_list, t_flags *flags, t_lmods *lmods)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	if (**ptr && lmods->hh)
		str = ft_itoa_base(va_arg(a_list, unsigned char), 16);
	else if (**ptr && lmods->h)
		str = ft_itoa_base(va_arg(a_list, unsigned short int), 16);
	else if (**ptr && lmods->l)
		str = ft_itoa_base(va_arg(a_list, unsigned long int), 16);
	else if (**ptr && lmods->ll)
		str = ft_itoa_base(va_arg(a_list, unsigned long long int), 16);
	else if (**ptr && lmods->j)
		str = ft_itoa_base(va_arg(a_list, uintmax_t), 16);
	else if (**ptr && lmods->z)
		str = ft_itoa_base(va_arg(a_list, size_t), 16);
	else 
		str = ft_itoa_base(va_arg(a_list, unsigned int), 16);
	if (flags && flags->space && !flags->plus)
	{
		write(1, " ", 1);
		len++;
	}
	if (flags && flags->hash)
	{
		if (is_cap(ptr))
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

int	is_spec(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		   	c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%');
}

int is_flag(int c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int is_length(int c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

void	store_type(int *len, va_list a_list, t_flags *flags, t_lmods *lmods)
{
	if (*ptr && (**ptr == 's'))
		*len += s_spec(a_list, &*flags, &*lmods);
	else if (*ptr && **ptr == 'p')
		*len += p_spec(a_list, &*flags);
	else if (*ptr && (**ptr == 'd' || **ptr == 'i'))
		*len += d_spec(a_list, &*flags, &*lmods);
	else if (*ptr && (**ptr == 'o'))
		*len += o_spec(a_list, &*flags, &*lmods);
	else if (*ptr && (**ptr == 'u'))
		*len += u_spec(a_list, &*flags, &*lmods);
	else if (*ptr && (**ptr == 'x'))
		*len += x_spec(a_list, &*flags, &*lmods);
	else if (*ptr && (**ptr == 'c'))
		*len += c_spec(a_list, &*flags, &*lmods);
	else if (*ptr && **ptr == '%')
		*len += double_percent();
}

void	flag_check(char **ptr, t_flags *flags)
{
	if (*ptr && **ptr == '#')
		flags->hash = 1;
	else if (*ptr && ft_isdigit(**ptr) == 1)
		flags->width = 1;
	else if (*ptr && **ptr == '0')
		flags->zero = 1;
	else if (*ptr && **ptr == '-')
		flags->dash = 1;
	else if (*ptr && **ptr == ' ')
	{
		while(**ptr == ' ')
			ptr++;
		flags->plus = 1
	}
	else if (*ptr && **ptr == '+')
		flags->plus = 1;
}

void	length_check(char **ptr, t_lmods *length)
{
	if (*ptr && **ptr == 'h')
	{
		if (*ptr && *(*ptr + 1) == 'h')
		{
			length->hh = 1;
			**ptr++;
		}
		else
			length->h = 1;
	}
	else if (*ptr && **ptr == 'l')
	{
		if (*ptr && *(*ptr + 1) == 'l')
		{
			length->ll = 1;
			ptr++;
		}
		else
			length->l = 1;
	}
	else if (*ptr && **ptr == 'j')
		length->j = 1;
	else if (*ptr && **ptr == 'z')
		length->z = 1;
}

int	print_final_format(va_list a_list, const char *format)
{
	int	len;
	t_flags	*flags;
	t_lmods	*lmods;
	char	*ptr;

	len = 0;
	flags = ft_init_flags();
	lmods = ft_init_lmods();
	ptr = (char *)format;
	while (*ptr)
	{
		if (*ptr && *ptr == '%')
		{
			ptr++;
			while (*ptr && !is_spec(*ptr))
			{
				else if(is_flag(*ptr) && !is_digit(*ptr) && !is_length(*ptr))
				{
					flag_check(&ptr, flags);
					ptr++;
				}
				else if(!is_flag(*ptr) && is_digit(*ptr) && !is_length(*ptr))
				{
					parse_minfw(&ptr, flags);
					ptr++;
				}
				else if (!is_flag(*ptr) && !is_digit(*ptr) && is_length(*ptr))
				{
					length_check(&ptr, lmods);
					ptr++;
				}
				else if (!is_digit(*ptr) && !is_flag(*ptr) && !is_length(*ptr))
					return (-1);
			}
			if (*ptr && is_spec(*ptr))
			{
				if (is_cap(*ptr))
					flags->caps = 1;
				store_type(&len, a_list, flags, lmods);
			}
		}
		else if (*ptr && *ptr != '%')
		{
			write(1, ptr, 1);
			len++;
		}
		ft_init_flags();
		ptr++;
	}
	free(flags);
	free(lmods);
	return (len);
}

int ft_printf(const char *format, ...)
{
	va_list a_list;
	int		len;

	len =0;
	if (format)
	{
		va_start(a_list, format);
		len = print_final_format(a_list, format);
		va_end(a_list);
	}
	return (len);
}

/*
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	int len;
	int mylen;
	wchar_t str[] = L"0x1F479";
	int ft;

	ft = 42;
	len = 0;
	mylen = 0;
	len = printf("%ls%s knows his %s%c", str, "Torrey", "stuff", '\n');
	mylen = ft_printf("%o%s knows his %s%c", ft, "Torrey", "stuff", '\n');
	printf("len = %i\nmylen = %i\n", len, mylen);
	return(0);
}*/