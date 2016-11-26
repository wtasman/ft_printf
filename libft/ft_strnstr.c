/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:22:02 by wasman            #+#    #+#             */
/*   Updated: 2016/10/01 20:05:46 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lit;

	i = 0;
	j = 0;
	lit = ft_strlen(little);
	if (!lit)
		return (char *)(big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (j == lit - 1)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
