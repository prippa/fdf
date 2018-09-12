/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_output_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:10:07 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:10:09 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fpf_base_u_logic(t_printf *fpf, int len)
{
	if (fpf->width)
	{
		if (fpf->f[F_ZERO] && !fpf->precision)
			fpf_cat_char_len(fpf, fpf->width - len, '0');
		else
			fpf_cat_char_len(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (fpf->precision)
		fpf_cat_char_len(fpf, fpf->precision - len, '0');
	fpf_cat_str_len(fpf, fpf->str, len);
}

void		fpf_output_u(t_printf *fpf)
{
	int	len;

	len = ft_strlen(fpf->str);
	if (fpf->f[F_DOT] && !fpf->precision && fpf->str[0] == '0')
		len = 0;
	if (fpf->f[F_MINUS])
	{
		if (fpf->precision)
			fpf_cat_char_len(fpf, fpf->precision - len, '0');
		fpf_cat_str_len(fpf, fpf->str, len);
		if (fpf->width)
			fpf_cat_char_len(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	else
		fpf_base_u_logic(fpf, len);
}
