/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 10:46:03 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 21:03:02 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_input(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_puts_precision(str, flags.dot);
	else
		count += ft_puts_precision(str, ft_strlen(str));
	return (count);
}

int			ft_handle_string(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_input(str, flags);
	if (flags.dot >= 0)
		count += ft_handle_width(flags.width, flags.dot, 0);
	else
		count += ft_handle_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_input(str, flags);
	return (count);
}
