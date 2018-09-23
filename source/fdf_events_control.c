#include "fdf.h"

static void	fdf_button_event_2(int key, t_fdf *fdf)
{
	if (key == PLUS_KEY)
		--fdf->zoom;
	else if (key == MINUS_KEY)
		++fdf->zoom;
	else if (key == KEY_9)
		fdf->z_divisor += 0.5;
	else if (key == KEY_0)
		fdf->z_divisor -= 0.5;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	if (fdf->z_divisor < 0.3)
		fdf->z_divisor = 0.3;
	else if (fdf->z_divisor > 30)
		fdf->z_divisor = 30;
}

static void	fdf_button_event_1(int key, t_fdf *fdf)
{
	if (key == KEY_7)
	{
		fdf_reset(fdf);
		fdf->projection = 0;
	}
	else if (key == KEY_8)
	{
		fdf_reset(fdf);
		fdf->projection = 1;
	}
	else if (key == RIGHT_ARROW_KEY)
		fdf->x_offset += 10;
	else if (key == LEFT_ARROW_KEY)
		fdf->x_offset -= 10;
	else if (key == UP_ARROW_KEY)
		fdf->y_offset -= 10;
	else if (key == DOWN_ARROW_KEY)
		fdf->y_offset += 10;
	else
		fdf_button_event_2(key, fdf);
}

int			fdf_button_event(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
		fdf_exit(fdf);
	else if (key == KEY_1)
		fdf->gamma += 0.05;
	else if (key == KEY_2)
		fdf->gamma -= 0.05;
	else if (key == KEY_3)
		fdf->alpha -= 0.05;
	else if (key == KEY_4)
		fdf->alpha += 0.05;
	else if (key == KEY_5)
		fdf->beta -= 0.05;
	else if (key == KEY_6)
		fdf->beta += 0.05;
	else
		fdf_button_event_1(key, fdf);
	fdf_draw(fdf);
	return (0);
}

int			fdf_close(t_fdf *fdf)
{
	fdf_exit(fdf);
	return (0);
}