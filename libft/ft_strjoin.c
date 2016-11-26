/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 21:41:07 by wasman            #+#    #+#             */
/*   Updated: 2016/10/01 22:03:36 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	str = (char*)malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
		str[k++] = s1[i++];
	while (s2[j] != '\0')
		str[k++] = s2[j++];
	str[j + i] = '\0';
	return (str);
}
