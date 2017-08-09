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

int	print_final_format(va_list a_list, const char *format)
{
	int	len;
	t_mods	*mods;
	char	*ptr;

	len = 0;
	mods = ft_init_mods();
	ptr = (char *)format;
	while (*ptr)
	{
		if (*ptr && *ptr == '%')
		{
			ptr++;
			while (*ptr && !is_spec(*ptr))
			{
				if(is_flag(*ptr) && !ft_isdigit(*ptr) && !is_length(*ptr))
				{
					flag_check(&ptr, mods);
					ptr++;
				}
				else if(!is_flag(*ptr) && ft_isdigit(*ptr) && !is_length(*ptr))
				{
					write(1, "fixmfw", 6);
					ptr++;
				}
				else if (!is_flag(*ptr) && !ft_isdigit(*ptr) && is_length(*ptr))
				{
					length_check(&ptr, mods);
					ptr++;
				}
				else if (!ft_isdigit(*ptr) && !is_flag(*ptr) && !is_length(*ptr))
					return (-1);
			}
			if (*ptr && is_spec(*ptr))
			{
				if (is_cap(*ptr))
					mods->caps = 1;
				store_type(&len, a_list, mods, &ptr);
			}
		}
		else if (*ptr && *ptr != '%')
		{
			write(1, ptr, 1);
			len++;
		}
		ft_init_mods();
		ptr++;
	}
	free(mods);
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