/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:57:02 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/27 12:49:11 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_deal_width(const char *s, size_t i, t_info *info, va_list ap)
{
	int		width;

	width = 0;
	if (s[i] == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			info->align = -1;
			if (info->empty == '0')
				info->empty = ' ';
			width *= -1;
		}
		info->width = width;
		return (i + 1);
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		width *= 10;
		width += s[i] - '0';
		i++;
	}
	info->width = width;
	return (i);
}
