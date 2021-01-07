/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_guide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 21:57:07 by najlee            #+#    #+#             */
/*   Updated: 2021/01/07 17:15:32 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_flag(t_guide *guide)
{
	guide->align = 'r';
	guide->blank = ' ';
	guide->width = 0;
	guide->precision = -1;
	guide->sign = 1;
	guide->format = '\0';
	guide->check = 0;
}

int		ft_fill_flag(const char *str, int i, t_guide *guide)
{
	ft_init_flag(guide);
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			guide->align = 'l';
		else if (str[i] == '0')
			guide->blank = '0';
		++i;
	}
	return (i);
}

int		ft_fill_width(const char *str, int i, t_guide *guide, va_list ap)
{
	if (str[i] == '*')
	{
		guide->width = va_arg(ap, int);
		if (guide->width < 0)
		{
			guide->align = 'l';
			guide->width *= -1;
		}
		++i;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			guide->width *= 10;
			guide->width += str[i] - '0';
			++i;
		}
	}
	return (i);
}

int		ft_fill_precision(const char *str, int i, t_guide *guide, va_list ap)
{
	int precision;

	precision = 0;
	if (str[i] == '.')
	{
		guide->check = 1;
		if (str[++i] == '*')
		{
			guide->precision = va_arg(ap, int);
			if (guide->precision < 0)
			{
				guide->sign = -1;
				guide->precision *= -1;
			}
			return (++i);
		}
		if (str[i] == '-')
			i++;
		if (str[i] == '-')
			guide->sign = -1;
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				precision = (precision * 10) + (str[i++] - '0');
			guide->precision = precision;	
		}
	}
	return (i);
}

int		ft_fill_format(const char *str, int i, t_guide *guide)
{
	if (str[i] == '%' || str[i] == 'c' || str[i] == 'd' ||
			str[i] == 'i' || str[i] == 's' || str[i] == 'p' ||
			str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
	{
		guide->format = str[i];
		i++;
	}
	if (guide->check == 1 && guide->format != 'p' && guide->precision == -1)
		guide->precision = 0;
	return (i);
}
