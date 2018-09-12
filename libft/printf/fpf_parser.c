/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:26:54 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 15:26:56 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fpf_get_size_flag(t_printf *fpf)
{
	while (*fpf->format)
	{
		if (*fpf->format == 'l' && *(fpf->format + 1) == 'l')
		{
			fpf->size_flag = SF_LL;
			++fpf->format;
		}
		else if (*fpf->format == 'l')
			fpf->size_flag = SF_L;
		else if (*fpf->format == 'h' && *(fpf->format + 1) == 'h')
		{
			fpf->size_flag = SF_HH;
			++fpf->format;
		}
		else if (*fpf->format == 'h')
			fpf->size_flag = SF_H;
		else if (*fpf->format == 'j')
			fpf->size_flag = SF_J;
		else if (*fpf->format == 'z')
			fpf->size_flag = SF_Z;
		else
			break ;
		++fpf->format;
	}
}

static void	fpf_get_precision(t_printf *fpf)
{
	if (*fpf->format == '.')
	{
		fpf->f[F_DOT] = (char)1;
		++fpf->format;
		if (*fpf->format == '*')
		{
			fpf->precision = (int)va_arg(fpf->args, int);
			++fpf->format;
		}
		else
			while (ft_isdigit(*fpf->format))
				fpf->precision = (fpf->precision * 10) + (*fpf->format++ - '0');
	}
}

static void	fpf_get_width(t_printf *fpf)
{
	if (*fpf->format == '*')
	{
		if ((fpf->width = (int)va_arg(fpf->args, int)) < 0)
		{
			fpf->f[F_MINUS] = 1;
			fpf->width = ABS(fpf->width);
		}
		++fpf->format;
	}
	else
		while (ft_isdigit(*fpf->format))
			fpf->width = (fpf->width * 10) + (*fpf->format++ - '0');
}

static void	fpf_get_flags(t_printf *fpf)
{
	char c;

	c = 1;
	while (*(++fpf->format))
		if (*fpf->format == '-')
			fpf->f[F_MINUS] = c;
		else if (*fpf->format == '+')
			fpf->f[F_PLUS] = c;
		else if (*fpf->format == ' ')
			fpf->f[F_SPACE] = c;
		else if (*fpf->format == '#')
			fpf->f[F_SHARP] = c;
		else if (*fpf->format == '0')
			fpf->f[F_ZERO] = c;
		else if (*fpf->format == '~')
		{
			fpf->color = (int)va_arg(fpf->args, int);
			fpf->f[F_COLOR] = c;
		}
		else if (*fpf->format == '^')
			fpf->f[F_UPERCASE] = c;
		else
			break ;
}

void		fpf_parser(t_printf *fpf)
{
	fpf_get_flags(fpf);
	fpf_get_width(fpf);
	fpf_get_precision(fpf);
	fpf_get_size_flag(fpf);
	fpf_get_type(fpf);
}
