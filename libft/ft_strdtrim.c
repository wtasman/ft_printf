/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:22:25 by wasman            #+#    #+#             */
/*   Updated: 2016/10/05 10:27:43 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdtrim(char const *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	len;
	char	*cpy;

	if (s)
	{
		if (ft_strlen(s) == 0)
			return ("");
		i = 0;
		len = ft_strlen((char *)(s)) - 1;
		while (s[i] == c)
			i++;
		cpy = (char *)malloc(sizeof(char) * (len - i + 1));
		if (cpy == NULL)
			return (NULL);
		while ((s[len] == c) && (len > 0))
			len--;
		j = 0;
		while (i <= len)
			ft_strcpy(&cpy[j++], &s[i++]);
		cpy[j] = '\0';
		return (cpy);
	}
	return (NULL);
}
