#include "fdf.h"

static void		fdf_draw_usage(t_fdf *fdf)
{
	if (!fdf->draw_usage)
	{
		mlx_string_put(fdf->mlx, fdf->win, 25, 25, UC,
			"Press 'Enter' to see Usage");
		return ;
	}
	mlx_string_put(fdf->mlx, fdf->win, 25, 25, UC,
		"Press 'Enter' to hide Usage");
	mlx_string_put(fdf->mlx, fdf->win, 35, 50, UC, "[ESC] - close");
	mlx_string_put(fdf->mlx, fdf->win, 35, 75, UC, "[Arrows] - move figure");
	mlx_string_put(fdf->mlx, fdf->win, 35, 100, UC, "Rotate by X - [3] [4]");
	mlx_string_put(fdf->mlx, fdf->win, 35, 125, UC, "Rotate by Y - [5] [6]");
	mlx_string_put(fdf->mlx, fdf->win, 35, 150, UC, "Rotate by Z - [1] [2]");
	mlx_string_put(fdf->mlx, fdf->win, 35, 175, UC, "Zoom - [-] [+]");
	mlx_string_put(fdf->mlx, fdf->win, 35, 200, UC,
		"Decrease/Increase Z - [9] [0]");
	mlx_string_put(fdf->mlx, fdf->win, 35, 225, UC, "[TAB] - change color");
	mlx_string_put(fdf->mlx, fdf->win, 35, 250, UC, "[SPACE] - reset map");
}

static void		fdf_transform_to_iso_projection(t_point *p)
{
    int32_t previous_x;
    int32_t previous_y;

    previous_x = p->x;
    previous_y = p->y;
    p->x = (previous_x - previous_y) * cos(0.523599);
    p->y = -p->z + (previous_x + previous_y) * sin(0.523599);
}

static void		fdf_set_color(t_fdf *fdf, t_point *p)
{
	if (!p->color)
	{
		if (fdf->color_type == DEFAULT)
			p->color = FDF_DEFAULT_COLOR;
		else if (fdf->color_type == RED_COLOR)
			p->color = FDF_RED_COLOR;
		else if (fdf->color_type == GREEN_COLOR)
			p->color = FDF_GREEN_COLOR;
		else if (fdf->color_type == BLUE_COLOR)
			p->color = FDF_BLUE_COLOR;
		else if (fdf->color_type == RANDOM_COLOR)
			p->color = rand() % INT32_MAX;
	}
}

static t_point	fdf_get_converted_point(t_fdf *fdf, t_point p)
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

void			fdf_draw(t_fdf *fdf)
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
	fdf_draw_usage(fdf);
}
