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
