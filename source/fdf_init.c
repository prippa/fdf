#include "fdf.h"

void		fdf_init(t_fdf *fdf, const char *file_name)
{
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->file_name = file_name;
	fdf->i = 1;
}

void		fdf_window_init(t_fdf *fdf)
{
	if (!(fdf->mlx = mlx_init()))
		fdf_perror_exit(MLX_INIT_ERR, fdf);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME)))
		fdf_perror_exit(MLX_NEW_WIN_ERR, fdf);
	mlx_hook(fdf->win, 2, 0, fdf_button_event, fdf);
	mlx_hook(fdf->win, 17, 0, fdf_close, fdf);
}
