/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:31:41 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/31 02:03:09 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_deal_flag(const char *s, size_t i, t_info *info)
{
	while (s[i] == '-' || s[i] == '0' || s[i] == '#'
		|| s[i] == ' ' || s[i] == '+')
	{
		if (s[i] == '-')
		{
			if (info->empty == '0')
				info->empty = ' ';
			info->align = -1;
		}
		if (s[i] == '0' && info->align != -1)
			info->empty = '0';
		if (s[i] == '#')
			info->sharp = 1;
		if (s[i] == ' ')
			info->sign = ' ';
		if (s[i] == '+')
			info->sign = '+';
		i++;
	}
	return (i);
}
