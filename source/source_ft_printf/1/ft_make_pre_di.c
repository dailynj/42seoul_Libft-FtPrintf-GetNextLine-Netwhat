/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_pre_di.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:47:55 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/27 16:40:10 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_make_prefix_di(t_info *info, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (info->precision == 0 && str[0] == '0')
		str[0] = 0;
	if (len >= info->precision && info->precision != -1)
		info->empty = ' ';
	if (info->sign == '+' || info->sign == '-')
	{
		if (info->precision <= len)
			info->precision = -1;
		if (len < ft_max(info->width, info->precision))
			return (ft_pre_wp_comb(info, len, str));
		else
			return (ft_pre_only_sign(info));
	}
	else
		return (ft_make_prefix_xu(info, str));
}

char	*ft_pre_wp_comb(t_info *info, int len, char *str)
{
	if (info->precision == -1 && info->align == -1)
		return (ft_pre_only_sign(info));
	else if (info->precision == -1 && info->align == 1 && info->empty == '0')
		return (ft_pre_sign_zero_w(info, len));
	else if (info->width > info->precision && info->align != -1)
		return (ft_pre_space_sign_zero(info, len, str));
	else
		return (ft_pre_sign_zero_p(info, len));
}

char	*ft_pre_sign_zero_w(t_info *info, int len)
{
	char	*ret;

	if (!(ret = ft_calloc((info->width - len), 1)))
		return (NULL);
	len = info->width - len;
	ret[0] = info->sign;
	while ((--len) >= 1)
		ret[len] = '0';
	return (ret);
}

char	*ft_pre_sign_zero_p(t_info *info, int len)
{
	char	*ret;

	if (!(ret = ft_calloc(info->precision - len + 2, 1)))
		return (NULL);
	ret[0] = info->sign;
	len = info->precision - len + 1;
	while ((--len) >= 1)
		ret[len] = '0';
	return (ret);
}

char	*ft_pre_space_sign_zero(t_info *info, int len, char *str)
{
	char	*ret;

	if (!(ret = ft_calloc(info->width - len + 2, 1)))
		return (NULL);
	len = len >= info->precision ?
		info->width - len - 1 : info->width - len;
	if (info->precision < (int)ft_strlen(str))
		ret[len] = info->sign;
	else
		ret[ft_min(len, info->width -
				ft_max(0, info->precision)) - 1] = info->sign;
	while ((--len) >= 0)
	{
		if (ret[len] == info->sign)
			continue ;
		if (info->width - ft_max(0, info->precision) > len)
			ret[len] = ' ';
		else
			ret[len] = '0';
	}
	return (ret);
}
