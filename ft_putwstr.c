# include "ft_printf.h"

void	ft_putwstr(int *str)
{	
	int i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putwchar(str[i]);
		i++;
	}
}