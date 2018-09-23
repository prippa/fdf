#include "fdf.h"

static void	fdf_set_pixel(t_fdf *fdf, t_point *p, int32_t color)
{
	int32_t i;

	if (!color)
		color = 0xffffff;
	if (p->x > 0 && p->x < WIN_WIDTH && p->y > 0 && p->y < WIN_HEIGHT)
	{
		i = (p->x * fdf->bits_per_pixel / 8) + (p->y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
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
		fdf_set_pixel(fdf, &p0, (p0.color ? p0.color : p1.color));
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
