/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:45:36 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/27 15:34:34 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_deal_format(const char *s, size_t i, t_info *info)
{
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' ||
		s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' ||
		s[i] == '%' || s[i] == 'n' || s[i] == 'f' || s[i] == 'g' ||
		s[i] == 'e')
		info->format = s[i++];
	return (i);
}
