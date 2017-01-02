/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:31:07 by wasman            #+#    #+#             */
/*   Updated: 2017/01/02 08:52:14 by wasman           ###   ########.fr       */
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

void	store_type(char **ptr,int *len)
{
	if (*ptr && **ptr == ' ')
		*len += space_flag(&*ptr);
	if (*ptr && **ptr == '%')
		*len += double_percent();
}

int	print_final_format(const char *format)
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
			store_type(&ptr, &len);
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
		len = print_final_format(format);
		va_end(a_list);
	}
	return (len);
}

/*int main(void)
{
	int len;
	int mylen;

	len = 0;
	mylen = 0;
	len = printf("%%Torrey\n");
	mylen = ft_printf("%    %Trrey\n");
	printf("len = %i\nmylen = %i\n", len, mylen);
	return(0);
}*/
