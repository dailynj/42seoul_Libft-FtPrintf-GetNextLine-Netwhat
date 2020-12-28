/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:03:03 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/22 12:02:25 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_lstdel(t_list *ptr, void (*del)(void *))
{
	if (ptr->next)
		ft_lstdel(ptr->next, del);
	del(ptr->content);
	free(ptr);
}

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !*lst)
		return ;
	ft_lstdel(*lst, del);
	*lst = NULL;
}
