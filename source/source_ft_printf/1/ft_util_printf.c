/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:59:08 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/30 13:25:40 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_make_prefix(t_info *info, char *str)
{
	char	*ret;
	char	f;

	f = info->format;
	ret = NULL;
	if (f == 'd' || f == 'i')
		ret = ft_make_prefix_di(info, str);
	else if (f == 'x' || f == 'X' || f == 'u')
		ret = ft_make_prefix_xu(info, str);
	else if (f == 's')
		ret = ft_make_prefix_s(info, str);
	else if (f == 'c' || f == '%')
		ret = ft_make_prefix_c(info, str);
	else if (f == 'p')
		ret = ft_make_prefix_p(info, str);
	return (ret);
}

char	*ft_make_prefix_xu(t_info *info, char *str)
{
	char	*ret;
	int		len;
	int		str_len;

	if (info->precision == 0 && str[0] == '0')
		str[0] = 0;
	str_len = ft_strlen(str);
	len = ft_strlen(str);
	if (len > ft_max(info->width, info->precision))
		return (ft_calloc(1, 1));
	if (!(ret = ft_calloc(ft_max(info->width, info->precision) - len + 1, 1)))
		return (NULL);
	len = info->align == 1 ? ft_max(info->width, info->precision)
	- len : info->precision - len;
	while ((--len) >= 0)
	{
		if (info->align == 1 && info->width -
			info->precision > len && info->precision != -1)
			ret[len] = ' ';
		else if (info->precision < str_len && info->empty != '0')
			ret[len] = ' ';
		else
			ret[len] = '0';
	}
	return (ret);
}

char	*ft_make_prefix_c(t_info *info, char *str)
{
	char	*ret;
	int		len;

	if (info->precision == 0 && str[0] == '0')
		len = 0;
	else
		len = 1;
	if (info->align == -1)
		return (ft_calloc(1, 1));
	if (!(ret = ft_calloc(info->width - len + 2, 1)))
		return (NULL);
	len = info->width - len;
	while ((--len) >= 0)
		ret[len] = info->empty;
	return (ret);
}

char	*ft_make_prefix_s(t_info *info, char *str)
{
	char	*ret;
	int		len;

	len = ft_strlen(str);
	if (info->precision != -1)
	{
		len = ft_min(ft_strlen(str), info->precision);
		str[len] = 0;
	}
	if (len > info->width || info->align == -1)
		return (ft_calloc(1, 1));
	if (!(ret = ft_calloc(info->width - len + 1, 1)))
		return (0);
	len = info->width - len;
	while ((--len) >= 0)
		ret[len] = info->empty;
	return (ret);
}

void	ft_put_aligned(t_info *info, char *str, char *pre)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str) + ft_strlen(pre);
	ft_putstr_fd(pre, 1);
	g_printsize += ft_strlen(pre);
	if (info->format == 'c' && str[0] == 0)
	{
		ft_putchar_fd(str[0], 1);
		g_printsize++;
		len = 1 + ft_strlen(pre);
	}
	ft_putstr_fd(str, 1);
	g_printsize += ft_strlen(str);
	if (info->align == -1 && info->empty == ' ')
		while (info->width >= (++len) && ++g_printsize)
			ft_putchar_fd(info->empty, 1);
}
