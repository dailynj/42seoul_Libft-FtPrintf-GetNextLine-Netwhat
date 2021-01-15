/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:27:07 by mkal              #+#    #+#             */
/*   Updated: 2021/01/12 20:39:45 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/ft_printf.h"

static t_flags	ft_initialize(void)
{
	t_flags flags;

	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.blank = 0;
	return (flags);
}

static int		ft_parse_flags(const char *str, int i, t_flags *flags,
		va_list args)
{
	while (str[i])
	{
		if (!ft_isconversion(str[i]) && !ft_isflag(str[i])
				&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == ' ')
			flags->blank = 1;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_star_flag(args, *flags);
		if (str[i] == '.')
			i = ft_dot_flag(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_width_digit_flag(str[i], *flags);
		if (ft_isconversion(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int		ft_handle_input(const char *str, va_list args)
{
	int		i;
	int		count;
	t_flags flags;

	i = 0;
	count = 0;
	while (str[i])
	{
		flags = ft_initialize();
		if (str[i] != '%')
			count += ft_putchar_ret(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse_flags(str, ++i, &flags, args);
			if (ft_isconversion(str[i]))
				count += ft_handle((char)flags.type, flags, args);
			else if (str[i])
				count += ft_putchar_ret(str[i]);
		}
		i++;
	}
	return (count);
}

int				ft_printf(const char *fmt, ...)
{
	va_list	args;
	char	*str;
	int		count;

	count = 0;
	if (!(str = ft_strdup(fmt)))
		return (0);
	va_start(args, fmt);
	count += ft_handle_input(str, args);
	va_end(args);
	free((char*)str);
	return (count);
}
