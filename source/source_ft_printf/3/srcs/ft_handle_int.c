/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:23:18 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 21:03:45 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_input(char *str, int num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0 && (num < 0 && num >= INT_MIN))
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_handle_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count += ft_puts_precision(str, ft_strlen(str));
	return (count);
}

static int	ft_put_int(char *str, int num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.blank > 0)
		ft_putchar(' ');
	if (flags.minus == 1)
		count += ft_input(str, num, flags);
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
		count += ft_input(str, num, flags);
	return (count);
}

int			ft_handle_int(int i, t_flags flags)
{
	int		count;
	long	num;
	char	*str;

	count = 0;
	num = i;
	if (flags.dot == 0 && i == 0)
	{
		count += ft_handle_width(flags.width, 0, 0);
		return (count);
	}
	if (num < 0 && (flags.dot >= 0 || flags.zero == 1) && num >= INT_MIN)
	{
		if (flags.dot <= -1 && flags.zero == 1)
			ft_putchar('-');
		num *= -1;
		flags.zero = 1;
		flags.blank = 0;
		flags.width--;
		count++;
	}
	str = ft_itoa_long(num);
	count += ft_put_int(str, i, flags);
	free(str);
	return (count);
}
