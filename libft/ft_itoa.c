/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:08:54 by wasman            #+#    #+#             */
/*   Updated: 2016/10/09 23:05:01 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_intstr(int n, int len)
{
	char	*str;

	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (len--)
	{
		str[len] = (n % 10 + '0');
		n = n / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nn;
	int		i;

	len = 1;
	i = 0;
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	nn = n;
	while (nn /= 10)
		len++;
	len += i;
	str = ft_intstr(n, len);
	if (!str)
		return (NULL);
	if (i)
		str[0] = '-';
	return (str);
}
