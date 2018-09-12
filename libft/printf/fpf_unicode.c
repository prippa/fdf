/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_unicode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:40:35 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 16:40:36 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		fpf_wcharlen(wchar_t wc)
{
	if (wc <= 0x7f)
		return (1);
	else if (wc <= 0x7ff)
		return (2);
	return (3);
}

static size_t	fpf_wstrlen(wchar_t *ws)
{
	size_t	len;

	if (!ws)
		return (0);
	len = -1;
	while (ws[++len])
		;
	return (len);
}

static size_t	fpf_wbytelen(wchar_t *ws)
{
	size_t	byte_len;
	size_t	len;

	byte_len = 0;
	len = fpf_wstrlen(ws);
	while (len--)
		byte_len += fpf_wcharlen(*ws++);
	return (byte_len);
}

static int		fpf_pull_wchar(wchar_t wc, char *new_obj, int i)
{
	int		size;

	size = fpf_wcharlen(wc);
	if (size == 1)
		new_obj[i++] = wc;
	else if (size == 2)
	{
		new_obj[i++] = (wc >> 6) + 0xC0;
		new_obj[i++] = (wc & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		new_obj[i++] = (wc >> 12) + 0xE0;
		new_obj[i++] = ((wc >> 6) & 0x3F) + 0x80;
		new_obj[i++] = (wc & 0x3F) + 0x80;
	}
	else
	{
		new_obj[i++] = (wc >> 18) + 0xF0;
		new_obj[i++] = ((wc >> 12) & 0x3F) + 0x80;
		new_obj[i++] = ((wc >> 6) & 0x3F) + 0x80;
		new_obj[i++] = (wc & 0x3F) + 0x80;
	}
	return (i);
}

char			*fpf_wstr_to_str(wchar_t *ws)
{
	char	*new_obj;
	int		len;

	len = fpf_wbytelen(ws);
	if (!(new_obj = (char *)malloc(sizeof(char) * len + 1)))
		fpf_malloc_error_exit();
	new_obj[len] = 0;
	len = 0;
	while (*ws)
		len = fpf_pull_wchar(*ws++, new_obj, len);
	return (new_obj);
}
