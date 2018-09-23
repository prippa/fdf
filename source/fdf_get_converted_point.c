#include "fdf.h"

static void	fdf_rotate_x(int32_t *y, int32_t *z, double alpha)
{
	int32_t previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	fdf_rotate_y(int32_t *x, int32_t *z, double beta)
{
	int32_t previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void	fdf_rotate_z(int32_t *x, int32_t *y, double gamma)
{
	int32_t previous_x;
	int32_t previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

static void	fdf_transform_to_iso_projection(int32_t *x, int32_t *y, int32_t z)
{
    int32_t previous_x;
    int32_t previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point		fdf_get_converted_point(t_fdf *fdf, t_point p)
{
	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.x -= (fdf->x_size * fdf->zoom) / 2;
	p.y -= (fdf->y_size * fdf->zoom) / 2;
	p.z *= fdf->zoom / fdf->z_divisor;
	fdf_rotate_x(&p.y, &p.z, fdf->alpha);
	fdf_rotate_y(&p.x, &p.z, fdf->beta);
	fdf_rotate_z(&p.x, &p.y, fdf->gamma);
	if (!fdf->projection)
		fdf_transform_to_iso_projection(&p.x, &p.y, p.z);
	p.x += WIN_WIDTH / 2 + fdf->x_offset;
	p.y += (WIN_HEIGHT + fdf->y_size * fdf->zoom) / 2.5 + fdf->y_offset;
	return (p);
}
