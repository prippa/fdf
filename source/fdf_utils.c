#include "fdf.h"

void		fdf_print_usage(void)
{
	ft_printf("Usage: ./fdf [map]\n");
}

void		fdf_parser_new_line_logic(t_fdf *fdf, t_point *tp)
{
	static char	flag;

	if (!flag)
	{
		fdf->x_size = tp->x;
		flag = 1;
	}
	else if (tp->x && tp->x != fdf->x_size)
		fdf_parser_error_exit(fdf, tp->y + 1, fdf->i,
			"invalid point(s) size in line");
	++tp->y;
	tp->x = 1;
	fdf->i = 1;
}

void		fdf_reset(t_fdf *fdf)
{
	fdf->gamma = 0;
	fdf->beta = 0;
	fdf->alpha = 0;
	fdf->z_divisor = 1;
	fdf->x_offset = 0;
	fdf->y_offset = 0;
	fdf->zoom = MIN(WIN_WIDTH / fdf->x_size / 2, WIN_HEIGHT / fdf->y_size / 2);
}
