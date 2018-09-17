#include "fdf.h"

void		fdf_free(t_fdf *fdf)
{
	// ft_lst2del(&fdf->p_start, &fdf->p_end, NULL);
}

void		fdf_perror_exit(const char *message, t_fdf *fdf)
{
	fdf_free(fdf);
	ft_perror_exit(message);
}

void		fdf_parser_error_exit(t_fdf *fdf,
			uint32_t y, uint32_t x, const char *message)
{
	fdf_free(fdf);
	ft_dprintf(2, "Line %u, Column %u : %s\n", y, x, message);
	exit(-1);
}

void		fdf_exit(t_fdf *fdf)
{
	fdf_free(fdf);
	exit(0);
}
