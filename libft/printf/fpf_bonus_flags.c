#include "ft_printf.h"

void		fpf_before_processing_data(t_printf *fpf)
{
	if (fpf->f[F_COLOR])
		fpf_set_color(fpf);
	if (fpf->f[F_UPERCASE])
		ft_str_to_upper(&fpf->str);
}

void		fpf_after_processing_data(t_printf *fpf)
{
	if (fpf->f[F_COLOR])
		fpf_cat_str(fpf, COLOR_RESET);
}
