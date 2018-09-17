/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:58:36 by prippa            #+#    #+#             */
/*   Updated: 2017/11/20 18:01:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	char	sign;
	int		res;

	sign = 0;
	res = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		++str;
	}
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (sign ? -res : res);
}

long long int	ft_atoi_max(char *str)
{
	char			sign;
	long long int	res;

	sign = 0;
	res = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		++str;
	}
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (sign ? -res : res);
}

int				ft_base(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

long long int	ft_atoi_base(const char *str, int base)
{
	char			sign;
	long long int	res;
	int				current;

	res = 0;
	sign = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		++str;
	}
	while ((current = ft_base(*str++)) > -1)
		res = (res * base) + current;
	return (sign ? -res : res);
}
