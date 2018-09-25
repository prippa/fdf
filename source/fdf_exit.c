#include "fdf.h"

void		fdf_perror_exit(const char *message, t_fdf *fdf)
{
	fdf_free(fdf);
	ft_perror_exit(message);
}

void		fdf_parser_error_exit(t_fdf *fdf,
			uint32_t y, uint32_t x, const char *message)
{
	fdf_free(fdf);
	if (!y && !x)
		ft_dprintf(2, "ERROR: fdf: %s\n", message);
	else
		ft_dprintf(2, "ERROR: fdf: Line %u, Column %u : %s\n", y, x, message);
	exit(-1);
}

void		fdf_exit(t_fdf *fdf)
{
	fdf_free(fdf);
	// system("leaks -q fdf");
	exit(0);
}
