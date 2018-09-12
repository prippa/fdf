/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:44:21 by prippa            #+#    #+#             */
/*   Updated: 2018/02/26 15:44:26 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(size_t y, size_t x, int c)
{
	char **arr;
	char ch;

	ch = 0;
	if (!(arr = (char **)malloc(sizeof(char *) * (y + 1))))
		return (NULL);
	arr[y] = NULL;
	while (y--)
	{
		if (!(arr[y] = (char *)malloc(sizeof(char) * (x + 1))))
			return (NULL);
		ft_memset(arr[y], c, x);
		arr[y][x] = ch;
	}
	return (arr);
}
