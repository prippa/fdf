#include "fdf.h"

static void	fdf_transform_to_iso_projection(t_point *p)
{
    int32_t previous_x;
    int32_t previous_y;

    previous_x = p->x;
    previous_y = p->y;
    p->x = (previous_x - previous_y) * cos(0.523599);
    p->y = -p->z + (previous_x + previous_y) * sin(0.523599);
}

static void	fdf_set_color(t_fdf *fdf, t_point *p)
{
	if (!p->color)
	{
		if (fdf->color_type == DEFAULT)
			p->color = 0x30d5c8;
		else if (fdf->color_type == RED_COLOR)
			p->color = 0xff0000;
		else if (fdf->color_type == GREEN_COLOR)
			p->color = 0x00ff00;
		else if (fdf->color_type == BLUE_COLOR)
			p->color = 0x0000ff;
		else if (fdf->color_type == RANDOM_COLOR)
			p->color = rand() % INT32_MAX;
	}
}

t_point		fdf_get_converted_point(t_fdf *fdf, t_point p)
{
	fdf_set_color(fdf, &p);
	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.x -= (fdf->x_size * fdf->zoom) / 2;
	p.y -= (fdf->y_size * fdf->zoom) / 2;
	p.z *= fdf->zoom / fdf->z_divisor;
	fdf_rotate_x(fdf, &p);
	fdf_rotate_y(fdf, &p);
	fdf_rotate_z(fdf, &p);
	fdf_transform_to_iso_projection(&p);
	p.x += WIN_WIDTH / 2 + fdf->x_offset;
	p.y += (WIN_HEIGHT + fdf->y_size * fdf->zoom) / 2.5 + fdf->y_offset;
	return (p);
}
