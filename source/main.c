#include "fdf.h"

void test(t_fdf *fdf)
{
	t_list2 *tmp = fdf->p_start;

	while (tmp)
	{
		t_point *p = (t_point *)tmp->content;
		ft_printf("(x = %d, y = %d, z = %d, color = %u)\n", p->x, p->y, p->z, p->color);
		tmp = tmp->next;
	}
	exit(0);
}

int		main(int argc, char **argv)
{
	t_fdf fdf;

	if (argc == 2)
	{
		fdf_init(&fdf, argv[1]);
		fdf_parser(&fdf);
		test(&fdf);
		fdf_window_init(&fdf);
		fdf_run(&fdf);
		fdf_free(&fdf);
	}
	else
		fdf_print_usage();
	return (0);
}