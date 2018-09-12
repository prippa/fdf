/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:57:45 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:57:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const *start;
	char const *end;

	if (!s)
		return (NULL);
	start = s;
	while (ft_isspace(*start))
		++start;
	end = s;
	while (*end)
		++end;
	--end;
	while (ft_isspace(*end))
		--end;
	if (end < start)
		return (ft_strdup(""));
	return (ft_strsub(s, (start - s), (end - start + 1)));
}
