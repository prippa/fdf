/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:59:59 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 13:00:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char **dst, const char *src,
			size_t dstsize, size_t srcsize)
{
	char *tmp;

	tmp = *dst;
	if (!(*dst = (char *)malloc(sizeof(char) * (dstsize + srcsize + 1))))
		return (NULL);
	ft_strcpy(*dst, tmp);
	ft_strncpy(&(*dst)[dstsize], src, srcsize);
	(*dst)[dstsize + srcsize] = 0;
	free(tmp);
	return (*dst);
}
