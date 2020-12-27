/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:28:17 by suko              #+#    #+#             */
/*   Updated: 2020/12/27 16:06:29 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp1;
	t_list	*temp2;

	if (lst == 0 || del == 0)
		return ;
	temp1 = *lst;
	while (temp1 != 0)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		ft_lstdelone(temp2, del);
	}
	*lst = 0;
}
