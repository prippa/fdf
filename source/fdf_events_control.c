#include "fdf.h"

int		fdf_button_event(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
		fdf_exit(fdf);
	return (0);
}

int		fdf_close(t_fdf *fdf)
{
	fdf_exit(fdf);
	return (0);
}
