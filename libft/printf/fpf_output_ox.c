/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_output_ox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:10 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fpf_percision_tricks(t_printf *fpf, int *len)
{
	if (fpf->f[F_DOT] && !fpf->precision && fpf->str[0] == '0'
		&& !fpf->f[F_SHARP])
		*len = 0;
	if (fpf->f[F_DOT] && !fpf->precision && fpf->str[0] == '0'
		&& fpf->f[F_SHARP] && (fpf->type == 'x' || fpf->type == 'X'))
		*len = 0;
	if (fpf->f[F_DOT] && fpf->precision
		&& fpf->f[F_SHARP] && (fpf->type == 'o' || fpf->type == 'O'))
		fpf->f[F_SHARP] = 0;
}

static int		fpf_write_sharp(t_printf *fpf)
{
	if (fpf->type == 'x')
	{
		fpf_cat_str(fpf, "0x");
		return (2);
	}
	else if (fpf->type == 'X')
	{
		fpf_cat_str(fpf, "0X");
		return (2);
	}
	else if (fpf->type == 'o' || fpf->type == 'O')
	{
		fpf_cat_char(fpf, '0');
		return (1);
	}
	return (0);
}

static void		fpf_base_ox_logic(t_printf *fpf, int len)
{
	if (fpf->width && fpf->f[F_SHARP] && fpf->type != 'o'
		&& fpf->type != 'O')
		fpf->width -= 2;
	else if (fpf->width && fpf->f[F_SHARP] && (fpf->type == 'o'
		|| fpf->type == 'O'))
		fpf->width--;
	if (fpf->width)
	{
		if (fpf->f[F_ZERO] && !fpf->precision)
		{
			if (fpf->f[F_SHARP])
				fpf_write_sharp(fpf);
			fpf_cat_char_len(fpf, fpf->width - len, '0');
		}
		else
			fpf_cat_char_len(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (fpf->f[F_SHARP] && fpf->str[0] != '0'
		&& (!fpf->f[F_ZERO] || !fpf->width))
		fpf_write_sharp(fpf);
	if (fpf->precision)
		fpf_cat_char_len(fpf, fpf->precision - len, '0');
	fpf_cat_str_len(fpf, fpf->str, len);
}

void			fpf_output_ox(t_printf *fpf)
{
	int	len;
	int	size;

	len = ft_strlen(fpf->str);
	fpf_percision_tricks(fpf, &len);
	size = 0;
	if (fpf->f[F_MINUS])
	{
		if (fpf->f[F_SHARP] && len)
			size += fpf_write_sharp(fpf);
		if (fpf->precision)
			fpf_cat_char_len(fpf, fpf->precision - len, '0');
		fpf_cat_str_len(fpf, fpf->str, len);
		if (fpf->width)
			fpf_cat_char_len(fpf,
			fpf->width - MAX(len, fpf->precision) - size, ' ');
	}
	else
		fpf_base_ox_logic(fpf, len);
}
