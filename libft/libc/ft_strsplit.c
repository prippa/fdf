/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:59:58 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 14:00:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_size(char const *s, char c)
{
	size_t size;

	size = 0;
	while (*s)
		if (*s != c)
		{
			++size;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	len;

	if (!s || !c
		|| !(res = (char **)malloc(sizeof(char *) * (ft_get_size(s, c) + 1))))
		return (NULL);
	i = -1;
	while (*s)
		if (*s != c)
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				++len;
			if (!(res[++i] = ft_strsub(s, 0, len)))
				return (NULL);
			s += len;
		}
		else
			++s;
	res[++i] = NULL;
	return (res);
}
