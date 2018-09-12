#include "fdf.h"

int		fdf_deal_key(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf fdf;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 500, 500, "hallo");
	mlx_key_hook(fdf.win_ptr, fdf_deal_key, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}