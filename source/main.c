#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf fdf;

	if (argc == 2)
	{
		fdf_init(&fdf, argv[1]);
		fdf_parser(&fdf);
		fdf_init_points(&fdf);
		fdf_init_window(&fdf);
		fdf_run(&fdf);
		fdf_exit(&fdf);
	}
	else
		fdf_print_usage();
	return (0);
}