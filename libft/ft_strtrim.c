/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:24:15 by wasman            #+#    #+#             */
/*   Updated: 2016/10/09 14:19:06 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	int		j;
	size_t	len;
	char	*cpy;

	if (!s)
		return (NULL);
	i = 0;
	j = 1;
	len = ft_strlen((char *)(s)) - 1;
	while (ft_isspace(s[len]) && (len > 0))
		len--;
	while (ft_isspace(s[i]) && (len != 0))
		i++;
	if (len == 0)
		j = 0;
	cpy = ft_strsub(s, i, (len - i + j));
	if (cpy == NULL)
		return (NULL);
	return (cpy);
}
