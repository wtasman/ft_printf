#include "ft_printf.h"

t_mods	*ft_init_mods(void)
{
	t_mods *mods;

	mods = (t_mods *)malloc(sizeof(t_mods));
	mods->width = 0;
	mods->hash = 0;
	mods->zero = 0;
	mods->dash = 0;
	mods->plus = 0;
	mods->space = 0;
	mods->caps = 0;
	mods->hh = 0;
	mods->h = 0;
	mods->l = 0;
	mods->ll = 0;
	mods->j = 0;
	mods->z = 0;
	return (mods);
}