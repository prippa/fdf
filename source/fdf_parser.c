/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:29:49 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:29:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_valid_color(t_fdf *fdf, char **s, t_point *tp)
{
	++fdf->j;
	if (!*(++*s) || **s == ' ' || **s == '\n')
		return ;
	if (*((*s)++) == '0' && (**s == 'x' || **s == 'X'))
		++*s;
	else
		fdf_parser_error_exit(fdf, fdf->i, fdf->j, PARS_MISS_HEX_ERR);
	fdf->j += 2;
	if (ft_base(**s) == -1)
		fdf_parser_error_exit(fdf, fdf->i, fdf->j, PARS_NO_VALUE_HEX_ERR);
	while ((fdf->c = ft_base(**s)) > -1)
	{
		tp->color = (tp->color * 16) + fdf->c;
		++fdf->j;
		++*s;
	}
	if (**s && **s != ' ' && **s != '\n')
		fdf_parser_error_exit(fdf, fdf->i, fdf->j, PARS_SUNTAX_ERR);
}

static void	fdf_valid_z(t_fdf *fdf, char **s, t_point *tp)
{
	fdf->c = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			fdf->c = -1;
		++*s;
		++fdf->j;
	}
	if (!ft_isdigit(**s))
		fdf_parser_error_exit(fdf, fdf->i, fdf->j, PARS_SUNTAX_ERR);
	while (ft_isdigit(**s))
	{
		tp->z = (tp->z * 10) + (**s - '0');
		++fdf->j;
		++*s;
	}
	if (tp->z > FDF_Z_MAX)
		fdf_parser_error_exit(fdf, fdf->i, fdf->j, PARS_Z_ERR);
	tp->z *= fdf->c;
}

static void	fdf_valid_point(t_fdf *fdf, char **s, t_point *tp)
{
	t_list		*new_obj;

	fdf_valid_z(fdf, s, tp);
	if (**s == ',')
		fdf_valid_color(fdf, s, tp);
	else if (**s && **s != ' ' && **s != '\n')
		fdf_parser_error_exit(fdf, fdf->i, fdf->j, PARS_SUNTAX_ERR);
	if (!(new_obj = ft_lstnew(tp, sizeof(t_point))))
		fdf_perror_exit(MALLOC_ERR, fdf);
	ft_lstadd(&fdf->points, new_obj);
	tp->z = 0;
	tp->color = 0;
	++tp->x;
}

static void	fdf_parser_new_line_logic(t_fdf *fdf, t_point *tp)
{
	static char	flag;

	if (tp->x > 1)
	{
		if (!flag)
		{
			fdf->x_size = tp->x;
			flag = 1;
		}
		else if (tp->x != fdf->x_size)
			fdf_parser_error_exit(fdf, fdf->i, fdf->j, PARS_INVALID_X);
		++tp->y;
		tp->x = 1;
	}
	++fdf->i;
	fdf->j = 1;
}

void		fdf_parse_file(t_fdf *fdf, char *s)
{
	t_point		tp;

	ft_bzero(&tp, sizeof(t_point));
	tp.x = 1;
	tp.y = 1;
	while (*s)
	{
		if (*s == '\n')
			fdf_parser_new_line_logic(fdf, &tp);
		else if (*s == ' ')
			++fdf->j;
		else
		{
			fdf_valid_point(fdf, &s, &tp);
			continue ;
		}
		++s;
	}
	if (!fdf->points)
		fdf_parser_error_exit(fdf, 0, 0, PARS_EMPTY_MAP);
	fdf_parser_new_line_logic(fdf, &tp);
}
