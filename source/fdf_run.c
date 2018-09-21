#include "fdf.h"

static void iso(int32_t *x, int32_t *y, int32_t z)
{
    int32_t previous_x;
    int32_t previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void test(t_fdf *fdf)
{
	fdf->i = 0;
	while (fdf->i < fdf->y_size)
	{
		fdf->j = 0;
		while (fdf->j < fdf->x_size)
		{
			iso(&fdf->p[fdf->i][fdf->j].x, &fdf->p[fdf->i][fdf->j].y, fdf->p[fdf->i][fdf->j].z);
			++fdf->j;
		}
		++fdf->i;
	}
	
	fdf->i = 0;
	while (fdf->i < fdf->y_size)
	{
		fdf->j = 0;
		while (fdf->j < fdf->x_size)
		{
			fdf_draw_line(fdf, (t_line)
			{
				.x0 = fdf->p[fdf->i][fdf->j].x * 35,
				.y0 = fdf->p[fdf->i][fdf->j].y * 35,
				.x1 = (fdf->p[fdf->i][fdf->j].x * 35),
				.y1 = (fdf->p[fdf->i][fdf->j].y * 35) + 35
			});
			fdf_draw_line(fdf, (t_line)
			{
				.x0 = fdf->p[fdf->i][fdf->j].x * 35,
				.y0 = fdf->p[fdf->i][fdf->j].y * 35,
				.x1 = (fdf->p[fdf->i][fdf->j].x * 35) + 35,
				.y1 = (fdf->p[fdf->i][fdf->j].y * 35)
			});
			++fdf->j;
		}
		++fdf->i;
	}
	// exit(0);
}

void		fdf_run(t_fdf *fdf)
{
	test(fdf);
	mlx_loop(fdf->mlx);
}
