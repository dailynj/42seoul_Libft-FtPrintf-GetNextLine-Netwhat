/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_pre_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:47:55 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/27 16:41:16 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_make_prefix_p(t_info *info, char *str)
{
	int		len;

	if (info->precision == 0 && str[0] == '0')
		str[0] = 0;
	len = ft_strlen(str);
	if (len >= info->precision && info->precision != -1)
		info->empty = ' ';
	if (info->precision <= len)
		info->precision = -1;
	if (len + 2 < ft_max(info->width, info->precision))
		return (ft_pre_wp_comb_p(info, len, str));
	else
		return (ft_pre_only_sign_p());
}

char	*ft_pre_wp_comb_p(t_info *info, int len, char *str)
{
	if (info->precision == -1 && info->align == -1)
		return (ft_pre_only_sign_p());
	else if (info->precision == -1 && info->align == 1 && info->empty == '0')
		return (ft_pre_sign_zero_w_p(info, len));
	else if (info->width > info->precision && info->align != -1)
		return (ft_pre_space_sign_zero_p(info, len, str));
	else
		return (ft_pre_sign_zero_p_p(info, len));
}

char	*ft_pre_sign_zero_w_p(t_info *info, int len)
{
	char	*ret;

	if (!(ret = ft_calloc((info->width - len) + 2, 1)))
		return (NULL);
	len = info->width - len;
	ret[0] = '0';
	ret[1] = 'x';
	while ((--len) >= 2)
		ret[len] = '0';
	return (ret);
}

char	*ft_pre_sign_zero_p_p(t_info *info, int len)
{
	char	*ret;

	if (!(ret = ft_calloc(info->precision - len + 2, 1)))
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	len = info->precision - len + 2;
	while ((--len) >= 2)
		ret[len] = '0';
	return (ret);
}

char	*ft_pre_space_sign_zero_p(t_info *info, int len, char *str)
{
	char	*ret;

	if (!(ret = ft_calloc(info->width - len + 2, 1)))
		return (NULL);
	len = len >= info->precision ?
		info->width - len - 1 : info->width - len;
	if (info->precision < (int)ft_strlen(str) && len != 0)
		ft_set_p_zerox(len, ret);
	else
	{
		if (len < info->width - ft_max(0, info->precision) - 1)
			ft_set_p_zerox(info->width - ft_max(0, info->precision) - 1, ret);
		else
			ft_set_p_zerox(len, ret);
	}
	while ((--len) >= 0)
	{
		if (ret[len] == 'x' || ret[len] == '0')
			continue ;
		if (info->width - ft_max(0, info->precision) > len)
			ret[len] = ' ';
		else
			ret[len] = '0';
	}
	return (ret);
}
