/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:38:15 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:40:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **lst, t_list *new_obj)
{
	new_obj->next = *lst;
	*lst = new_obj;
}

void	ft_lst2_push_front(t_list2 **start, t_list2 **end, t_list2 *new_obj)
{
	new_obj->next = *start;
	new_obj->prev = NULL;
	if (*start)
		(*start)->prev = new_obj;
	else
		*end = new_obj;
	*start = new_obj;
}

void	ft_lst2_push_back(t_list2 **start, t_list2 **end, t_list2 *new_obj)
{
	new_obj->next = NULL;
	new_obj->prev = *end;
	if (*end)
		(*end)->next = new_obj;
	else
		*start = new_obj;
	*end = new_obj;
}
