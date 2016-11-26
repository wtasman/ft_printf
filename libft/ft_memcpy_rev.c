/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:39:01 by wasman            #+#    #+#             */
/*   Updated: 2016/09/27 14:13:56 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	char		*ndst;
	const char	*nsrc;

	ndst = (char *)dst;
	nsrc = (const char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (n > 0)
	{
		ndst[n] = nsrc[n];
		n--;
	}
	return (dst);
}
