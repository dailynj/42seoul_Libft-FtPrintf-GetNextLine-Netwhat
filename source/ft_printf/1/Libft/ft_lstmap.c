/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:15:31 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/22 15:47:53 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstfreeall(t_list *lst, void (*del)(void *))
{
	if (lst->next)
		ft_lstfreeall(lst->next, del);
	del(lst->content);
	free(lst);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst)
		return (NULL);
	if (!(start = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next ? lst->next : lst;
	while (lst->next)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
			return (ft_lstfreeall(start, del));
		ft_lstadd_back(&start, tmp);
		lst = lst->next;
	}
	if (ft_lstsize(start) > 1)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
			return (ft_lstfreeall(start, del));
		ft_lstadd_back(&start, tmp);
	}
	return (start);
}
