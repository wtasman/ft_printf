/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:13:53 by wasman            #+#    #+#             */
/*   Updated: 2016/09/30 14:20:13 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	void	*new;

	new = (void*)malloc(sizeof(void) * size);
	i = 0;
	if (!new || size == 0)
		return (NULL);
	else
		ft_bzero(new, size);
	return (new);
}
