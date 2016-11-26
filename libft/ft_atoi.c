/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 19:07:47 by wasman            #+#    #+#             */
/*   Updated: 2016/10/07 14:28:58 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	nbr;
	int	sign;
	int	i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspaces(s[i]))
		s++;
	if (s[i] == '+')
	{
		i++;
	}
	if (s[i] == '-' && (i != 1))
	{
		i++;
		sign = (sign * -1);
	}
	while (ft_isdigit(s[i]))
	{
		nbr = (nbr * 10) + (s[i] - '0');
		i++;
	}
	return (nbr * sign);
}
