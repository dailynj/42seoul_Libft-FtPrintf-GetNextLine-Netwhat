/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:33:44 by suko              #+#    #+#             */
/*   Updated: 2020/12/27 15:45:43 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*result;

	if (lst == 0 || f == 0)
		return (0);
	temp = lst;
	new = ft_lstnew(f(temp->content));
	if (new == 0)
		return (0);
	result = new;
	temp = temp->next;
	while (temp != 0)
	{
		new = ft_lstnew(f(temp->content));
		if (new == 0)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new);
		temp = temp->next;
	}
	return (result);
}
