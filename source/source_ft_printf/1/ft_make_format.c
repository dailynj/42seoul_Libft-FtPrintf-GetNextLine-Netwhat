/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:16:34 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/31 17:46:19 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_make_format(t_info *info, va_list ap)
{
	char	*ptr;

	ptr = NULL;
	if (info->format == 'd' || info->format == 'i')
		ptr = ft_format_d(info, ap);
	else if (info->format == 'c')
		ptr = ft_format_c(ap);
	else if (info->format == 's')
		ptr = ft_format_s(ap);
	else if (info->format == 'x' || info->format == 'X')
		ptr = ft_format_x(ap, info->format);
	else if (info->format == 'u')
		ptr = ft_format_u(ap);
	else if (info->format == 'p')
		ptr = ft_format_p(ap);
	else if (info->format == '%')
	{
		if (!(ptr = ft_calloc(2, sizeof(char))))
			return (NULL);
		ptr[0] = '%';
	}
	return (ptr);
}

char	*ft_pre_only_sign(t_info *info)
{
	char	*ret;

	if (!(ret = ft_calloc(2, sizeof(char))))
		return (NULL);
	ret[0] = info->sign;
	return (ret);
}

char	*ft_pre_only_sign_p(void)
{
	char	*ret;

	if (!(ret = ft_calloc(3, sizeof(char))))
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	return (ret);
}
