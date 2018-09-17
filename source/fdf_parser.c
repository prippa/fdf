#include "fdf.h"

static void	fdf_valid_color(t_fdf *fdf, const char **s, t_point *tp)
{
	++fdf->i;
	if (!*(++*s) || **s == ' ' || **s == '\n')
		return ;
	if (*((*s)++) == '0' && (**s == 'x' || **s == 'X'))
		++*s;
	else
		fdf_parser_error_exit(fdf, tp->y + 1, fdf->i, "hex '0x' is missing");
	fdf->i += 2;
	if (ft_base(**s) == -1)
		fdf_parser_error_exit(fdf, tp->y + 1, fdf->i, "no value after '0x'");
	while ((fdf->c = ft_base(**s)) > -1)
	{
		tp->color = (tp->color * 16) + fdf->c;
		++fdf->i;
		++*s;
	}
	if (**s && **s != ' ' && **s != '\n')
		fdf_parser_error_exit(fdf, tp->y + 1, fdf->i, "syntax error");
}

static void	fdf_valid_z(t_fdf *fdf, const char **s, t_point *tp)
{
	fdf->c = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			fdf->c = -1;
		++*s;
		++fdf->i;
	}
	if (!ft_isdigit(**s))
		fdf_parser_error_exit(fdf, tp->y + 1, fdf->i, "syntax error");
	while (ft_isdigit(**s))
	{
		tp->z = (tp->z * 10) + (**s - '0');
		++fdf->i;
		++*s;
	}
	tp->z *= fdf->c;
}

static void	fdf_valid_point(t_fdf *fdf, const char **s, t_point *tp)
{
	t_list2 *new_obj;

	fdf_valid_z(fdf, s, tp);
	if (**s == ',')
		fdf_valid_color(fdf, s, tp);
	else if (**s && **s != ' ' && **s != '\n')
		fdf_parser_error_exit(fdf, tp->y + 1, fdf->i, "syntax error");
	if (!(new_obj = ft_lst2new(tp, sizeof(t_point))))
		fdf_perror_exit(MALLOC_ERR, fdf);
	ft_lst2_push_back(&fdf->p_start, &fdf->p_end, new_obj);
	tp->z = 0;
	tp->color = 0;
	++tp->x;
}

static void	fdf_parse_file(t_fdf *fdf, const char *s)
{
	t_point tp;

	ft_bzero(&tp, sizeof(t_point));
	while (*s)
	{
		if (*s == '\n')
		{
			++tp.y;
			tp.x = 0;
			fdf->i = 1;
			++s;
			continue ;
		}
		if (*s == ' ')
		{
			++fdf->i;
			++s;
		}
		else
			fdf_valid_point(fdf, &s, &tp);
	}
}

void		fdf_parser(t_fdf *fdf)
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
