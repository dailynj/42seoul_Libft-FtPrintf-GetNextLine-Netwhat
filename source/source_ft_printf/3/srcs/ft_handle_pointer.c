/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 09:48:40 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 21:04:06 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_input(char *pointer, unsigned long long num, t_flags flags)
{
	int	count;
	int	pointer_len;

	count = 0;
	if (num == 0 && flags.dot >= 0)
		pointer_len = 0;
	else
		pointer_len = ft_strlen(pointer);
	count += ft_puts_precision("0x", 2);
	if (flags.dot >= 0)
		count += ft_handle_width(flags.dot, pointer_len, 1);
	if (num == 0 && flags.dot >= 0)
		return (count);
	count += ft_puts_precision(pointer, ft_strlen(pointer));
	return (count);
}

int			ft_handle_pointer(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	p = ft_utoa_base(num, 16);
	p = ft_str_tolower(p);
	if (flags.minus == 1)
		count += ft_input(p, num, flags);
	if (num == 0 && flags.dot >= 0)
		count += ft_handle_width(flags.width, 2, 0);
	else
		count += ft_handle_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		count += ft_input(p, num, flags);
	free(p);
	return (count);
}
