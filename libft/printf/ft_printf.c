/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:56:51 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 12:56:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fpf_dispatcher(t_printf *fpf)
{
	fpf_before_processing_data(fpf);
	if (fpf->type == 's' || fpf->type == 'S')
		fpf_output_s(fpf);
	else if (fpf->type == 'd' || fpf->type == 'i' || fpf->type == 'D')
		fpf_output_d(fpf);
	else if (fpf->type == 'c' || fpf->type == 'C')
		fpf_output_c(fpf);
	else if (fpf->type == 'u' || fpf->type == 'U')
		fpf_output_u(fpf);
	else if (fpf->type == 'o' || fpf->type == 'O'
		|| fpf->type == 'x' || fpf->type == 'X')
		fpf_output_ox(fpf);
	else
		fpf_output_p(fpf);
	fpf_after_processing_data(fpf);
}

static void	fpf_handle_type(t_printf *fpf)
{
	fpf->size_flag = 0;
	fpf->width = 0;
	fpf->precision = 0;
	fpf->color = 0;
	fpf->type = 0;
	fpf->str = NULL;
	ft_bzero(fpf->f, FLAG_SIZE);
	fpf_parser(fpf);
	if (fpf->str)
	{
		fpf_dispatcher(fpf);
		free(fpf->str);
	}
}

static void	fpf_lobi(t_printf *fpf)
{
	while (*fpf->format)
	{
		if (*fpf->format == '%')
			fpf_handle_type(fpf);
		else
			fpf_cat_char(fpf, *fpf->format++);
	}
	if (fpf->buflen)
		fpf->len += write(fpf->fd, fpf->buf, fpf->buflen);
}

int			ft_printf(const char *format, ...)
{
	t_printf fpf;

	fpf.format = format;
	fpf.fd = 1;
	fpf.buflen = 0;
	fpf.len = 0;
	va_start(fpf.args, format);
	fpf_lobi(&fpf);
	va_end(fpf.args);
	return (fpf.len);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_printf fpf;

	fpf.format = format;
	fpf.fd = fd;
	fpf.buflen = 0;
	fpf.len = 0;
	va_start(fpf.args, format);
	fpf_lobi(&fpf);
	va_end(fpf.args);
	return (fpf.len);
}
