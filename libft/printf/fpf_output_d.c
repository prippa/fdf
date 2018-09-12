/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_output_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:08:50 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:08:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fpf_print_d(t_printf *fpf, int len, int len2)
{
	if (len < len2)
		fpf_cat_str(fpf, fpf->str + 1);
	else
		fpf_cat_str(fpf, fpf->str);
}

static void		fpf_print_if_psm(t_printf *fpf, int *len, int *flag)
{
	if (*flag)
	{
		if (fpf->f[F_PLUS] && fpf->str[0] != '-' && !(*flag = 0))
			fpf_cat_char(fpf, '+');
		else if (fpf->str[0] == '-' && !(*flag = 0))
		{
			fpf_cat_char(fpf, '-');
			*len -= 1;
		}
		else if (fpf->f[F_SPACE] && !(*flag = 0))
			fpf_cat_char(fpf, ' ');
	}
}

static void		fpf_base_d_logic(t_printf *fpf, int len, int flag)
{
	int tmp;

	if (fpf->width)
	{
		if (fpf->f[F_ZERO] && !fpf->precision)
		{
			tmp = len;
			fpf_print_if_psm(fpf, &len, &flag);
			fpf_cat_char_len(fpf, fpf->width - tmp, '0');
		}
		else
			fpf_cat_char_len(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (fpf->precision)
	{
		fpf_print_if_psm(fpf, &len, &flag);
		fpf_cat_char_len(fpf, fpf->precision - len, '0');
		fpf_print_d(fpf, len, ft_strlen(fpf->str));
	}
	else
	{
		fpf_print_if_psm(fpf, &len, &flag);
		fpf_print_d(fpf, len, ft_strlen(fpf->str));
	}
}

static void		fpf_logic_d_with_minus(t_printf *fpf, int len)
{
	int	size;

	size = 0;
	if (fpf->f[F_PLUS] && fpf->str[0] != '-' && (size += 1))
		fpf_cat_char(fpf, '+');
	else if (fpf->str[0] == '-' && (size += 1))
	{
		fpf_cat_char(fpf, '-');
		len--;
	}
	else if (fpf->f[F_SPACE] && (size += 1))
		fpf_cat_char(fpf, ' ');
	if (fpf->precision)
		fpf_cat_char_len(fpf, fpf->precision - len, '0');
	fpf_print_d(fpf, len, ft_strlen(fpf->str));
	if (fpf->width)
		fpf_cat_char_len(fpf,
			fpf->width - MAX(len, fpf->precision) - size, ' ');
}

void			fpf_output_d(t_printf *fpf)
{
	int	len;

	len = ft_strlen(fpf->str);
	if (fpf->precision < 0 && (fpf->precision = fpf->width))
		fpf->width = 0;
	if (fpf->f[F_DOT] && fpf->f[F_ZERO] && !fpf->precision)
		fpf->f[F_ZERO] = 0;
	if (fpf->str[0] == '0' && fpf->f[F_DOT])
		len = 0;
	if (fpf->f[F_MINUS])
		fpf_logic_d_with_minus(fpf, len);
	else
	{
		if (fpf->width && !fpf->f[F_MINUS]
		&& ((fpf->f[F_PLUS] && fpf->str[0] != '-')
		|| (fpf->f[F_SPACE] && fpf->str[0] != '-')
		|| (fpf->precision == len && fpf->str[0] == '-')
		|| (fpf->str[0] == '-' && !fpf->f[F_ZERO]
		&& fpf->precision && fpf->precision > len)))
			fpf->width--;
		fpf_base_d_logic(fpf, len, 1);
	}
}
