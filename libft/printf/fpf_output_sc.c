/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_output_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:49 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fpf_rules(t_printf *fpf, int len)
{
	if (fpf->f[F_MINUS])
	{
		fpf_cat_str_len(fpf, fpf->str, len);
		if (fpf->width)
			fpf_cat_char_len(fpf, fpf->width - len, ' ');
	}
	else
	{
		if (fpf->width)
		{
			if (fpf->f[F_ZERO])
				fpf_cat_char_len(fpf, fpf->width - len, '0');
			else
				fpf_cat_char_len(fpf, fpf->width - len, ' ');
		}
		fpf_cat_str_len(fpf, fpf->str, len);
	}
}

void		fpf_output_s(t_printf *fpf)
{
	int	len;

	len = ft_strlen(fpf->str);
	if (fpf->precision < 0)
		fpf->precision = 0;
	else if (fpf->precision)
	{
		if (fpf->type == 'S'
			&& !(fpf->str[fpf->precision - 1] >= 0
			&& fpf->str[fpf->precision - 1] <= 127))
		{
			while (fpf->precision % 3 > 0)
				fpf->precision--;
		}
		if (len > fpf->precision)
			len = fpf->precision;
	}
	else if (fpf->f[F_DOT])
		len = 0;
	fpf_rules(fpf, len);
}

void		fpf_output_c(t_printf *fpf)
{
	int len;

	if (!(len = ft_strlen(fpf->str)))
		++len;
	if (fpf->f[F_MINUS])
	{
		fpf_cat_str_len(fpf, fpf->str, len);
		if (fpf->width)
			fpf_cat_char_len(fpf, fpf->width - len, ' ');
	}
	else
	{
		if (fpf->width)
		{
			if (fpf->f[F_ZERO])
				fpf_cat_char_len(fpf, fpf->width - len, '0');
			else
				fpf_cat_char_len(fpf, fpf->width - len, ' ');
		}
		fpf_cat_str_len(fpf, fpf->str, len);
	}
}
