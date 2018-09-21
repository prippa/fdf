/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:37:46 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:40:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		del((*lst)->content, (*lst)->content_size);
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	ft_lst2del_by_obj(t_list2 **start, t_list2 **end,
			t_list2 *obj, void (*del)(void *, size_t))
{
	if (!obj)
		return ;
	if (!obj->prev)
	{
		*start = (*start)->next;
		if (*start)
			(*start)->prev = NULL;
		else
			*end = NULL;
	}
	else if (!obj->next)
	{
		obj->prev->next = NULL;
		*end = obj->prev;
	}
	else
	{
		obj->prev->next = obj->next;
		obj->next->prev = obj->prev;
	}
	del(obj->content, obj->content_size);
	free(obj);
}

void	ft_lst2del(t_list2 **start, t_list2 **end,
			void (*del)(void *, size_t))
{
	t_list2	*tmp;

	while (*start)
	{
		tmp = *start;
		del((*start)->content, (*start)->content_size);
		*start = (*start)->next;
		free(tmp);
	}
	*end = NULL;
}
