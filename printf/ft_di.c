/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:15:46 by najlee            #+#    #+#             */
/*   Updated: 2020/12/31 14:10:10 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_di_prefix(t_guide *guide, int nbrlen)
{
	int	len;

	if (guide->align == 'l')
		return (ft_calloc(1, 1));
	len = guide->width;
	if (len >= 1)
		--len;
	return (ft_blank_str(len, guide->blank));
}

char	*ft_di_surfix(t_guide *guide, int nbrlen)
{
	int len;
	
	if (guide->align == 'r')
		return (ft_calloc(1, 1));
	len = guide->width;
	if (len >= 1)
		--len;
	return (ft_blank_str(len, ' '));
}
