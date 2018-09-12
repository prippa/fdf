/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:55:18 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:55:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_obj;

	if (!s)
		return (NULL);
	if (!(new_obj = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strncpy(new_obj, &s[start], len);
	new_obj[len] = 0;
	return (new_obj);
}
