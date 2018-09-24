#include "fdf.h"

static void	fdf_set_pixel(t_fdf *fdf, t_point *p0)
{
	int32_t i;

	if (p0->x > 0 && p0->x < WIN_WIDTH && p0->y > 0 && p0->y < WIN_HEIGHT)
	{
		i = (p0->x * fdf->bits_per_pixel / 8) + (p0->y * fdf->size_line);
		fdf->data_addr[i] = p0->color;
		fdf->data_addr[++i] = p0->color >> 8;
		fdf->data_addr[++i] = p0->color >> 16;
	}
}

void		fdf_draw_line(t_fdf *fdf, t_point p0, t_point p1)
{
	t_draw_line_variables t;

	t.dx = ABS(p1.x - p0.x);
	t.dy = ABS(p1.y - p0.y);
	t.sx = (p0.x < p1.x ? 1 : -1);
	t.sy = (p0.y < p1.y ? 1 : -1);
	t.err = (t.dx > t.dy ? t.dx : -t.dy) / 2;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		fdf_set_pixel(fdf, &p0);
		t.e2 = t.err;
		if (t.e2 > -t.dx)
		{
			t.err -= t.dy;
			p0.x += t.sx;
		}
    	if (t.e2 < t.dy)
		{
			t.err += t.dx;
			p0.y += t.sy;
		}
	}
}
