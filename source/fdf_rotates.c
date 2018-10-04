/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:30:08 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:30:09 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_rotate_x(t_fdf *fdf, t_point *p)
{
	int32_t previous_y;

	previous_y = p->y;
	p->y = previous_y * cos(fdf->alpha) + p->z * sin(fdf->alpha);
	p->z = -previous_y * sin(fdf->alpha) + p->z * cos(fdf->alpha);
}

void	fdf_rotate_y(t_fdf *fdf, t_point *p)
{
	int32_t previous_x;

	previous_x = p->x;
	p->x = previous_x * cos(fdf->beta) + p->z * sin(fdf->beta);
	p->z = -previous_x * sin(fdf->beta) + p->z * cos(fdf->beta);
}

void	fdf_rotate_z(t_fdf *fdf, t_point *p)
{
	int32_t previous_x;
	int32_t previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = previous_x * cos(fdf->gamma) - previous_y * sin(fdf->gamma);
	p->y = previous_x * sin(fdf->gamma) + previous_y * cos(fdf->gamma);
}
