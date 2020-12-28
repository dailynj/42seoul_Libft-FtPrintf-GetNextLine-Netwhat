/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:31:58 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/28 21:00:45 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		g_printsize = 0;

int		ft_make_info(const char *s, size_t i, t_info *info, va_list ap)
{
	i = ft_deal_flag(s, i, info);
	i = ft_deal_width(s, i, info, ap);
	i = ft_deal_precision(s, i, info, ap);
	i = ft_deal_format(s, i, info);
	return (i);
}

void	ft_print_pretty(t_info *info, va_list ap)
{
	char	*str;
	char	*pre;
	int		printsize;

	printsize = 0;
	str = ft_make_format(info, ap);
	pre = ft_make_prefix(info, str);
	ft_put_aligned(info, str, pre);
	free(str);
	free(pre);
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_info		*info;
	size_t		i;

	g_printsize = 0;
	va_start(ap, s);
	i = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_init_info(info);
			i = ft_make_info(s, i + 1, info, ap);
			if (info->format == '\0')
				continue;
			ft_print_pretty(info, ap);
		}
		else if (++g_printsize)
			ft_putchar_fd(s[i++], 1);
	}
	free(info);
	va_end(ap);
	return (g_printsize);
}
