/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:49:36 by wasman            #+#    #+#             */
/*   Updated: 2016/10/07 14:51:08 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*ndst;
	const char		*nsrc;

	i = 0;
	ndst = (char *)dst;
	nsrc = (const char *)src;
	while (i < n)
	{
		if ((*ndst++ = *nsrc++) == c)
			return (ndst);
		i++;
	}
	return (NULL);
}
