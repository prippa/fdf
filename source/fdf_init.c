#include "fdf.h"

void		fdf_init_points(t_fdf *fdf)
{
	if (!(fdf->p = (t_point **)malloc(sizeof(t_point *) * fdf->y_size)))
		fdf_perror_exit(MALLOC_ERR, fdf);
	fdf->i = fdf->y_size;
	while (fdf->i--)
	{
		if (!(fdf->p[fdf->i] =
			(t_point *)malloc(sizeof(t_point) * fdf->x_size)))
			fdf_perror_exit(MALLOC_ERR, fdf);
		fdf->j = fdf->x_size;
		while (fdf->j--)
		{
			ft_memcpy(&fdf->p[fdf->i][fdf->j], fdf->points->content,
				sizeof(t_point));
			ft_lstpop(&fdf->points, fdf_point_del);
		}
	}
}

void		fdf_init(t_fdf *fdf, const char *file_name)
{
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->file_name = file_name;
	fdf->i = 1;
	fdf->z_divisor = 1;
}

void		fdf_init_window(t_fdf *fdf)
{
	if (!(fdf->mlx = mlx_init()))
		fdf_perror_exit(MLX_INIT_ERR, fdf);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME)))
		fdf_perror_exit(MLX_NEW_WIN_ERR, fdf);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT)))
		fdf_perror_exit(MLX_NEW_IMG_ERR, fdf);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
		&(fdf->size_line), &(fdf->endian));
	if ((fdf->zoom =
		MIN(WIN_WIDTH / fdf->x_size / 2, WIN_HEIGHT / fdf->y_size / 2)) < 1)
		fdf->zoom = 1;
	mlx_hook(fdf->win, 2, 0, fdf_button_event, fdf);
	mlx_hook(fdf->win, 17, 0, fdf_close, fdf);
}
