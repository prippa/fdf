/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:29:05 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:29:06 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_point_del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void	fdf_points_arr_del(t_fdf *fdf)
{
	while (fdf->y_size)
		free(fdf->p[--fdf->y_size]);
	fdf->x_size = 0;
	free(fdf->p);
	fdf->p = NULL;
}

void		fdf_free(t_fdf *fdf)
{
	ft_lstdel(&fdf->points, fdf_point_del);
	fdf_points_arr_del(fdf);
}
