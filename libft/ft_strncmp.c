/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 23:30:28 by wasman            #+#    #+#             */
/*   Updated: 2016/10/09 01:09:33 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (s1[j] != '\0' && s1[j] == s2[j] && j < n)
		j++;
	if (j == n)
		return (0);
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
