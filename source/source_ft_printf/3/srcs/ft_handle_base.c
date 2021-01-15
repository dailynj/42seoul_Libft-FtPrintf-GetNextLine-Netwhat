/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:19:06 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 21:01:53 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_input(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_handle_width(flags.dot, ft_strlen(str), 1);
	count += ft_puts_precision(str, ft_strlen(str));
	return (count);
}

static int	ft_put_str(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_handle_width(flags.width, 0, 0);
	}
	else
		count += ft_handle_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_input(str, flags);
	return (count);
}

int			ft_handle_base(unsigned int number, int lowercase,
		int base, t_flags flags)
{
	char	*str;
	int		count;

	number = (unsigned int)(4294967295 + 1 + number);
	count = 0;
	if (flags.dot == 0 && number == 0)
	{
		count += ft_handle_width(flags.width, 0, 0);
		return (count);
	}
	str = ft_utoa_base((unsigned long long)number, base);
	if (lowercase == 1)
		str = ft_str_tolower(str);
	count += ft_put_str(str, flags);
	free(str);
	return (count);
}
