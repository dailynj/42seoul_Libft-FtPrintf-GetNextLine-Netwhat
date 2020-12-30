/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:58:00 by najlee            #+#    #+#             */
/*   Updated: 2020/12/30 21:19:16 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_c_prefix(t_guide *guide)
{
	int	len;

	if (guide->align == 'l')
		return (0);
	len = guide->width;
	if (len >= 2)
		--len;
	return (ft_blank_str(len, guide->blank));
}

char	*ft_c_surfix(t_guide *guide)
{
	int len;
	
	if (guide->align == 'r')
		return (0);
	len = guide->width;
	if (len >= 2)
		--len;
	return (ft_blank_str(len, ' '));
}
