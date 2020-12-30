/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:48:50 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/30 13:29:20 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_format_p(va_list ap)
{
	char				*p;
	char				*str;
	unsigned long long	num;
	unsigned long long	tmp;
	int					len;

	p = "0123456789abcdef";
	num = va_arg(ap, unsigned long long);
	tmp = num;
	len = 0;
	if (tmp == 0)
		return (ft_strdup("0"));
	while (tmp && ++len)
		tmp /= 16;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while ((--len) >= 0)
	{
		str[len] = p[num % 16];
		num /= 16;
	}
	return (str);
}

void	ft_set_p_zerox(int idx, char *ret)
{
	ret[idx] = 'x';
	ret[idx - 1] = '0';
}

void	ft_init_info(t_info *info)
{
	info->align = 1;
	info->empty = ' ';
	info->sharp = 0;
	info->sign = ' ';
	info->width = -1;
	info->precision = -1;
	info->format = '\0';
}
