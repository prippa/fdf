#include "fdf.h"

void		fdf_draw(t_fdf *fdf)
{
	t_point tmp;

	ft_bzero(fdf->data_addr,
		WIN_WIDTH * WIN_HEIGHT * (fdf->bits_per_pixel / 8));
	fdf->i = -1;
	while (++fdf->i < fdf->y_size)
	{
		fdf->j = -1;
		while (++fdf->j < fdf->x_size)
		{
			tmp = fdf_get_converted_point(fdf, fdf->p[fdf->i][fdf->j]);
			if (fdf->j + 1 < fdf->x_size)
				fdf_draw_line(fdf, tmp,
					fdf_get_converted_point(fdf, fdf->p[fdf->i][fdf->j + 1]));
			if (fdf->i + 1 < fdf->y_size)
				fdf_draw_line(fdf, tmp,
					fdf_get_converted_point(fdf, fdf->p[fdf->i + 1][fdf->j]));
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void		fdf_run(t_fdf *fdf)
{
	srand(time(0));
	fdf_draw(fdf);
	mlx_loop(fdf->mlx);
}
