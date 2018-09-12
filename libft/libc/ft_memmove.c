/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:15:53 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 15:08:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	if (src < dst)
		ft_memcpy(dst, src, len);
	else
	{
		ptr1 = (unsigned char *)dst;
		ptr2 = (unsigned char *)src;
		while (len--)
			*ptr1++ = *ptr2++;
	}
	return (dst);
}
