#include "fdf.h"

void		fdf_draw_line(t_fdf *fdf, t_line l)
{
	t_draw_line_variables t;

	t.dx = ABS(l.x1 - l.x0);
	t.dy = ABS(l.y1 - l.y0);
	t.sx = (l.x0 < l.x1 ? 1 : -1);
	t.sy = (l.y0 < l.y1 ? 1 : -1);
	t.err = (t.dx > t.dy ? t.dx : -t.dy) / 2;
	while (l.x0 != l.x1 || l.y0 != l.y1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, l.x0, l.y0, 0xfffff);
		t.e2 = t.err;
		if (t.e2 > -t.dx)
		{
			t.err -= t.dy;
			l.x0 += t.sx;
		}
    	if (t.e2 < t.dy)
		{
			t.err += t.dx;
			l.y0 += t.sy;
		}
	}
}
