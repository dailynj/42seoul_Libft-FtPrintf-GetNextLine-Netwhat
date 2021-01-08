/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:58:00 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 23:15:13 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_c_prefix(t_guide *guide)
{
	int		len;
	char	*str;

	if (guide->align == 'l')
		return (str = ft_calloc(1, 1));
	len = guide->width;
	if (len >= 1)
		--len;
	return (str = ft_blank_str(len, guide->blank));
}

char		*ft_c_surfix(t_guide *guide)
{
	int		len;
	char	*str;

	if (guide->align == 'r')
		return (str = ft_calloc(1, 1));
	len = guide->width;
	if (len >= 1)
		--len;
	return (str = ft_blank_str(len, ' '));
}
