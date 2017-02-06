# include "ft_printf.h"

int	ft_putwstr(int *str)
{	
	int i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putwchar(str[i]);
		i++;
	}
	return (i);
}