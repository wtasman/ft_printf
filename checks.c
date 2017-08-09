#include "ft_printf.h"

int	double_percent(void)
{
	int len;

	len = 0;
	write(1, "%", 1);
	len++;
	return (len);
}

void	store_type(int *len, va_list a_list, t_mods *mods, char **ptr)
{
	if (*ptr && (**ptr == 's'))
		*len += s_spec(a_list, &*mods);
	else if (*ptr && **ptr == 'p')
		*len += p_spec(a_list);
	else if (*ptr && (**ptr == 'd' || **ptr == 'i'))
		*len += d_spec(a_list, &*mods);
	else if (*ptr && (**ptr == 'o'))
		*len += o_spec(a_list, &*mods);
	else if (*ptr && (**ptr == 'u'))
		*len += u_spec(a_list, &*mods);
	else if (*ptr && (**ptr == 'x'))
		*len += x_spec(a_list, &*mods);
	else if (*ptr && (**ptr == 'c'))
		*len += c_spec(a_list, &*mods);
	else if (*ptr && **ptr == '%')
		*len += double_percent();
}

void	flag_check(char **ptr, t_mods *mods)
{
	if (*ptr && **ptr == '#')
		mods->hash = 1;
	else if (*ptr && ft_isdigit(**ptr) == 1)
		mods->width = 1;
	else if (*ptr && **ptr == '0')
		mods->zero = 1;
	else if (*ptr && **ptr == '-')
		mods->dash = 1;
	else if (*ptr && **ptr == ' ')
	{
		while(*ptr && **ptr == ' ')
			ptr++;
		mods->plus = 1;
	}
	else if (*ptr && **ptr == '+')
		mods->plus = 1;
}

void	length_check(char **ptr, t_mods *mods)
{
	if (*ptr && **ptr == 'h')
	{
		if (*ptr && *(*ptr + 1) == 'h')
		{
			mods->hh = 1;
			ptr++;
		}
		else
			mods->h = 1;
	}
	else if (*ptr && **ptr == 'l')
	{
		if (*ptr && *(*ptr + 1) == 'l')
		{
			mods->ll = 1;
			ptr++;
		}
		else
			mods->l = 1;
	}
	else if (*ptr && **ptr == 'j')
		mods->j = 1;
	else if (*ptr && **ptr == 'z')
		mods->z = 1;
}


























