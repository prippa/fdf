/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:37:19 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:37:26 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void *, size_t))
{
	if (!*lst)
		return ;
	del((*lst)->content, (*lst)->content_size);
	free(*lst);
	*lst = NULL;
}

void	ft_lst2delone(t_list2 **obj, void (*del)(void *, size_t))
{
	if (!*obj)
		return ;
	del((*obj)->content, (*obj)->content_size);
	free(*obj);
	*obj = NULL;
}
