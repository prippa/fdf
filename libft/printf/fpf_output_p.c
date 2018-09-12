/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_output_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:36 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fpf_base_p_logic(t_printf *fpf, int len)
{
	int	flag;

	fpf->width -= 2;
	flag = 1;
	if (fpf->width > 0)
	{
		if (fpf->f[F_ZERO] && !fpf->precision)
		{
			flag = 0;
			fpf_cat_str(fpf, "0x");
			fpf_cat_char_len(fpf, fpf->width - len, '0');
		}
		else
			fpf_cat_char_len(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (flag)
		fpf_cat_str(fpf, "0x");
	if (fpf->precision)
		fpf_cat_char_len(fpf, fpf->precision - len, '0');
	fpf_cat_str_len(fpf, fpf->str, len);
}

void			fpf_output_p(t_printf *fpf)
{
	int	len;

	len = ft_strlen(fpf->str);
	if (fpf->f[F_DOT] && !fpf->precision && fpf->str[0] == '0')
		len = 0;
	if (fpf->f[F_MINUS])
	{
		fpf_cat_str(fpf, "0x");
		if (fpf->precision)
			fpf_cat_char_len(fpf, fpf->precision - len, '0');
		fpf_cat_str_len(fpf, fpf->str, len);
		if (fpf->width)
			fpf_cat_char_len(fpf,
				fpf->width - MAX(len, fpf->precision) - 2, ' ');
	}
	else
		fpf_base_p_logic(fpf, len);
}
