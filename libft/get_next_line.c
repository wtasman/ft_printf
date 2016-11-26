/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 00:18:13 by wasman            #+#    #+#             */
/*   Updated: 2016/11/22 16:00:15 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_in(int const fd, char **buff)
{
	char	read_buff[BUFF_SIZE + 1];
	char	*str;
	int		len;

	str = NULL;
	while ((!ft_strchr(*buff, '\n')))
	{
		if ((len = read(fd, read_buff, BUFF_SIZE)) <= 0)
			return (len);
		str = *buff;
		read_buff[len] = '\0';
		if (!(*buff = ft_strjoin(*buff, read_buff)))
			return (-1);
		ft_strdel(&str);
		if (len < BUFF_SIZE)
			return (len);
	}
	return (len);
}

char	*make(char *buff, char **line)
{
	char	*tmp;
	char	*free;

	free = buff;
	if (buff && (tmp = ft_strchr(buff, '\n')))
	{
		*line = ft_strsub(buff, 0, ft_strlen(buff) - ft_strlen(tmp));
		buff = ft_strdup(tmp + 1);
		ft_strdel(&free);
	}
	else
	{
		*line = ft_strdup(buff);
		ft_strclr(buff);
	}
	return (buff);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buff = NULL;
	int			ret;

	if (!line)
		return (-1);
	if (!buff)
		buff = ft_strnew(0);
	if ((ret = read_in(fd, &buff)) == -1)
		return (-1);
	buff = make(buff, line);
	if ((!ret && !ft_strlen(buff) && !ft_strlen(*line)))
		return (0);
	else
		return (1);
}
