/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:25:03 by suko              #+#    #+#             */
/*   Updated: 2020/12/27 15:59:33 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*old;

	if (lst == 0 || new == 0)
		return ;
	old = ft_lstlast(*lst);
	if (old == 0)
		*lst = new;
	else
		old->next = new;
}
