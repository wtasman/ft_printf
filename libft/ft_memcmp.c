/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:44:03 by wasman            #+#    #+#             */
/*   Updated: 2016/10/08 17:21:57 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char *ns1;
	unsigned const char *ns2;

	i = 0;
	ns1 = (unsigned const char *)s1;
	ns2 = (unsigned const char *)s2;
	if (s1 == 0 && s2 == 0)
		return (0);
	while (n--)
	{
		if (ns1[i] != ns2[i])
			return (ns1[i] - ns2[i]);
		i++;
	}
	return (0);
}
