/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:33:39 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/27 12:56:00 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_deal_precision(const char *s, size_t i, t_info *info, va_list ap)
{
	size_t	start;
	int		prec;

	start = i;
	prec = 0;
	if (s[i] == '.')
	{
		if (s[++i] == '*')
		{
			if ((prec = va_arg(ap, int)) >= 0)
				info->precision = prec;
			return (i + 1);
		}
		while (s[i] >= '0' && s[i] <= '9')
		{
			prec *= 10;
			prec += s[i++] - '0';
		}
		info->precision = prec;
		return (i);
	}
	else if (i != start)
		info->precision = prec;
	return (i);
}
