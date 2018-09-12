/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_parser_get_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:40:15 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 16:40:17 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_oux(t_printf *fpf)
{
	char	*str;

	if (*fpf->format == 'o')
		str = ft_itoa_base(fpf_conv_unsig_int(fpf), 8, 0);
	else if (*fpf->format == 'O')
	{
		fpf->size_flag = SF_L;
		str = ft_itoa_base(fpf_conv_unsig_int(fpf), 8, 0);
	}
	else if (*fpf->format == 'u')
		str = ft_itoa_base(fpf_conv_unsig_int(fpf), 10, 0);
	else if (*fpf->format == 'U')
	{
		fpf->size_flag = SF_L;
		str = ft_itoa_base(fpf_conv_unsig_int(fpf), 10, 0);
	}
	else if (*fpf->format == 'x')
		str = ft_itoa_base(fpf_conv_unsig_int(fpf), 16, 87);
	else
		str = ft_itoa_base(fpf_conv_unsig_int(fpf), 16, 55);
	return (str);
}

static char	*ft_get_s(t_printf *fpf)
{
	void	*data;
	char	*str;

	data = va_arg(fpf->args, void *);
	if (!data)
		str = ft_strdup("(null)");
	else if (*fpf->format == 'S' || fpf->size_flag == SF_L)
		str = fpf_wstr_to_str((wchar_t *)data);
	else
		str = ft_strdup((char *)data);
	return (str);
}

static char	*ft_get_di(t_printf *fpf)
{
	char	*str;

	if (*fpf->format == 'd' || *fpf->format == 'i')
		str = ft_itoa_max(fpf_conv_sig_int(fpf));
	else
	{
		fpf->size_flag = SF_L;
		str = ft_itoa_max(fpf_conv_sig_int(fpf));
	}
	return (str);
}

char		*ft_get_c(t_printf *fpf)
{
	char	*str;
	wchar_t	tmp[2];

	if (*fpf->format == 'C' || fpf->size_flag == SF_L)
	{
		tmp[0] = (wchar_t)va_arg(fpf->args, int);
		tmp[1] = 0;
		str = fpf_wstr_to_str(tmp);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = (char)va_arg(fpf->args, int);
		str[1] = 0;
	}
	return (str);
}

void		fpf_get_type(t_printf *fpf)
{
	if (*fpf->format == 's' || *fpf->format == 'S')
		fpf->str = ft_get_s(fpf);
	else if (*fpf->format == 'c' || *fpf->format == 'C')
		fpf->str = ft_get_c(fpf);
	else if (*fpf->format == 'd' || *fpf->format == 'D' || *fpf->format == 'i')
		fpf->str = ft_get_di(fpf);
	else if (*fpf->format == 'o' || *fpf->format == 'O'
			|| *fpf->format == 'u' || *fpf->format == 'U'
			|| *fpf->format == 'x' || *fpf->format == 'X')
		fpf->str = ft_get_oux(fpf);
	else if (*fpf->format == 'p')
		fpf->str = ft_itoa_base(va_arg(fpf->args, uintmax_t), 16, 87);
	else if (*fpf->format)
	{
		fpf_init_random_char(fpf);
		return ;
	}
	else
		return ;
	if (!fpf->str)
		fpf_malloc_error_exit();
	fpf->type = *fpf->format;
	++fpf->format;
}
