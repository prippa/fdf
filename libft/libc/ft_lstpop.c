/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:27:45 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:27:46 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpop(t_list **lst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	del(tmp->content, tmp->content_size);
	free(tmp);
}
