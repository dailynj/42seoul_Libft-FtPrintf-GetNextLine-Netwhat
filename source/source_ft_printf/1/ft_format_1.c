/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:21:58 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/27 14:25:18 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_format_d(t_info *info, va_list ap)
{
	int		d;
	int		temp;
	int		len;
	char	*ret;

	d = va_arg(ap, int);
	if (d == 0)
		return (ret = ft_strdup("0"));
	temp = d;
	len = 0;
	info->sign = (d < 0) ? '-' : info->sign;
	if (d == -2147483648)
		return (ret = ft_strdup("2147483648"));
	while (temp && ++len)
		temp /= 10;
	d = d < 0 ? d * -1 : d;
	if (!(ret = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while ((--len) >= 0)
	{
		ret[len] = (d % 10) + '0';
		d /= 10;
	}
	return (ret);
}

char	*ft_format_u(va_list ap)
{
	unsigned int	d;
	unsigned int	temp;
	int				len;
	char			*ret;

	d = va_arg(ap, unsigned int);
	temp = d;
	if (temp == 0)
		return (ret = ft_strdup("0"));
	len = 0;
	while (temp)
	{
		len++;
		temp /= 10;
	}
	if (!(ret = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while ((--len) >= 0)
	{
		ret[len] = (d % 10) + '0';
		d /= 10;
	}
	return (ret);
}

char	*ft_format_c(va_list ap)
{
	char	c;
	char	*ret;

	c = (char)va_arg(ap, int);
	if (!(ret = (char *)ft_calloc(2, sizeof(char))))
		return (NULL);
	ret[0] = c;
	return (ret);
}

char	*ft_format_s(va_list ap)
{
	char	*ret;
	char	*ptr;
	size_t	len;

	ptr = va_arg(ap, char *);
	if (!ptr)
	{
		ret = ft_calloc(7, sizeof(1));
		ft_strlcpy(ret, "(null)", 7);
		return (ret);
	}
	len = ft_strlen(ptr);
	if (!(ret = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(ret, ptr, len + 1);
	return (ret);
}

char	*ft_format_x(va_list ap, char c)
{
	char			*p;
	char			*str;
	unsigned int	num;
	unsigned int	tmp;
	size_t			len;

	p = (c == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	num = va_arg(ap, unsigned int);
	tmp = num;
	len = 0;
	if (tmp == 0)
		return (str = ft_strdup("0"));
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (len--)
	{
		str[len] = p[num % 16];
		num /= 16;
	}
	return (str);
}
