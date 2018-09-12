/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:58:54 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 21:52:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fpf_back_color(t_printf *fpf)
{
	if (fpf->color == F_BACK_GREEN_BLACK)
		fpf_cat_str(fpf, BACK_GREEN_BLACK);
	else if (fpf->color == F_BACK_BLUE_BLACK)
		fpf_cat_str(fpf, BACK_BLUE_BLACK);
	else if (fpf->color == F_BACK_RED_BLACK)
		fpf_cat_str(fpf, BACK_RED_BLACK);
	else if (fpf->color == F_BACK_CYAN_BLACK)
		fpf_cat_str(fpf, BACK_CYAN_BLACK);
	else if (fpf->color == F_BACK_GRAY_BLACK)
		fpf_cat_str(fpf, BACK_GRAY_BLACK);
	else if (fpf->color == F_BACK_GREEN_WHITE)
		fpf_cat_str(fpf, BACK_GREEN_WHITE);
	else if (fpf->color == F_BACK_BLUE_WHITE)
		fpf_cat_str(fpf, BACK_BLUE_WHITE);
	else if (fpf->color == F_BACK_RED_WHITE)
		fpf_cat_str(fpf, BACK_RED_WHITE);
	else if (fpf->color == F_BACK_CYAN_WHITE)
		fpf_cat_str(fpf, BACK_CYAN_WHITE);
	else
		fpf_cat_str(fpf, BOLD_GRAY);
}

static void	ft_fpf_bold_color(t_printf *fpf)
{
	if (fpf->color == F_BOLD_GRAY)
		fpf_cat_str(fpf, BOLD_GRAY);
	else if (fpf->color == F_BOLD_RED)
		fpf_cat_str(fpf, BOLD_RED);
	else if (fpf->color == F_BOLD_GREEN)
		fpf_cat_str(fpf, BOLD_GREEN);
	else if (fpf->color == F_BOLD_YELLOW)
		fpf_cat_str(fpf, BOLD_YELLOW);
	else if (fpf->color == F_BOLD_BLUE)
		fpf_cat_str(fpf, BOLD_BLUE);
	else if (fpf->color == F_BOLD_MAGENTA)
		fpf_cat_str(fpf, BOLD_MAGENTA);
	else if (fpf->color == F_BOLD_CYAN)
		fpf_cat_str(fpf, BOLD_CYAN);
	else if (fpf->color == F_BOLD_WHITE)
		fpf_cat_str(fpf, BOLD_WHITE);
	else
		ft_fpf_back_color(fpf);
}

void		fpf_set_color(t_printf *fpf)
{
	if (fpf->color == F_RED)
		fpf_cat_str(fpf, RED);
	else if (fpf->color == F_YELLOW)
		fpf_cat_str(fpf, YELLOW);
	else if (fpf->color == F_GREEN)
		fpf_cat_str(fpf, GREEN);
	else if (fpf->color == F_CYAN)
		fpf_cat_str(fpf, CYAN);
	else if (fpf->color == F_BLUE)
		fpf_cat_str(fpf, BLUE);
	else if (fpf->color == F_MAGENTA)
		fpf_cat_str(fpf, MAGENTA);
	else if (fpf->color == F_WHITE)
		fpf_cat_str(fpf, WHITE);
	else
		ft_fpf_bold_color(fpf);
}
