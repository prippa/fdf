#include "fdf.h"

static void	fdf_run(t_fdf *fdf)
{
	srand(time(0));
	fdf_draw(fdf);
	mlx_loop(fdf->mlx);
}

static void	fdf_parser(t_fdf *fdf)
{
	struct stat	stat_buff;
	char		*file;
	int			fd;

	if ((stat(fdf->file_name, &stat_buff)) == -1)
		fdf_perror_exit(fdf->file_name, fdf);
	if (!(file = (char *)malloc(sizeof(char) * (stat_buff.st_size + 1))))
		fdf_perror_exit(MALLOC_ERR, fdf);
	if ((fd = open(fdf->file_name, O_RDONLY)) == -1)
		fdf_perror_exit(fdf->file_name, fdf);
	if ((read(fd, file, stat_buff.st_size)) == -1)
		fdf_perror_exit(fdf->file_name, fdf);
	file[stat_buff.st_size] = 0;
	fdf_parse_file(fdf, file);
	free(file);
	close(fd);
}

int			main(int argc, char **argv)
{
	t_fdf fdf;

	if (argc == 2)
	{
		fdf_init(&fdf, argv[1]);
		fdf_parser(&fdf);
		fdf_init_points(&fdf);
		fdf_init_window(&fdf);
		fdf_run(&fdf);
	}
	ft_putstr(FDF_TEXT_USAGE);
	return (0);
}