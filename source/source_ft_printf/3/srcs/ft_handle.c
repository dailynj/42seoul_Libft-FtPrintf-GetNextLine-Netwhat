/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:32:12 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 21:02:13 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_isconversion(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p')
			|| (c == 'd') || (c == 'i') || (c == 'u')
			|| (c == 'x') || (c == 'X') || (c == '%')
			|| (c == 'o') || (c == 'O'));
}

int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '1') || (c == '-') || (c == ' '));
}

int	ft_handle(int c, t_flags flags, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_handle_char(va_arg(args, int), flags);
	else if (c == '%')
		count = ft_handle_percent(flags);
	else if (c == 'p')
		count = ft_handle_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = ft_handle_string(va_arg(args, char *), flags);
	else if ((c == 'd' || c == 'i'))
		count = ft_handle_int(va_arg(args, int), flags);
	else if (c == 'x')
		count += ft_handle_base(va_arg(args, unsigned int), 1, 16, flags);
	else if (c == 'X')
		count += ft_handle_base(va_arg(args, unsigned int), 0, 16, flags);
	else if (c == 'o' || c == 'O')
		count += ft_handle_base(va_arg(args, unsigned int), 0, 8, flags);
	else if (c == 'u')
		count += ft_handle_uint((unsigned int)va_arg(args, unsigned int),
				flags);
	return (count);
}
