/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:22:16 by wasman            #+#    #+#             */
/*   Updated: 2017/01/05 17:12:16 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct s_mods
{
	int width;
	int	hash;
	int	zero;
	int	dash;
	int	plus;
	int space;
	int	caps;
	int	hh;
	int h;
	int l;
	int ll;
	int j;
	int z;
}	t_mods;

int			ft_printf(const char *format, ...);
int			print_final_format(va_list a_list, const char *format);
t_mods		*ft_init_mods(void);
int 		x_spec(va_list a_list, t_mods *mods);
int 		o_spec(va_list a_list, t_mods *mods);
int 		d_spec(va_list a_list, t_mods *mods);
int 		u_spec(va_list a_list, t_mods *mods);
int			p_spec(va_list a_list);
int			c_spec(va_list a_list, t_mods *mods);
int			s_spec(va_list a_list, t_mods *mods);
void		store_type(int *len, va_list a_list, t_mods *mods, char **ptr);
void		flag_check(char **ptr, t_mods *mods);
void		parse_minfw(char **ptr, t_mods *mods);
void		length_check(char **ptr, t_mods *mods);
char		*ft_itoa_base(int value, int base);
size_t		ft_strlen(const char *);
void		ft_putstr(const char *);
void		ft_putchar(char c);
int			ft_isdigit(int c);
void		ft_putwchar(int c);
int			ft_putwstr(int *str);
int 		is_length(int c);
int 		is_flag(int c);
int			is_spec(int c);
int			is_cap(int c);





#endif