/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:22:16 by wasman            #+#    #+#             */
/*   Updated: 2016/12/30 22:28:49 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include "stdarg.h"

struct type_list
{
	char	*character;
}	type;

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

#endif
