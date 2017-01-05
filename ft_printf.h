/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:22:16 by wasman            #+#    #+#             */
/*   Updated: 2017/01/04 18:35:30 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

struct b_list
{
	int	hash;
	int	zero;
	int	dash;
	int	plus;
	int spac;
	int	hh;
	int h;
	int l;
	int ll;
	int j;
	int z;
}	flags;

int		ft_printf(const char *format, ...);
char	*ft_itoa_base(int value, int base);
size_t		ft_strlen(const char *);
void	ft_putstr(const char *);
void	ft_putchar(char c);

#endif
