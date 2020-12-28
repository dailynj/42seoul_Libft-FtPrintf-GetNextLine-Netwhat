/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:11:10 by najlee            #+#    #+#             */
/*   Updated: 2020/12/28 23:50:45 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	t_guide	guide;
	int		i;

	i = 0;
	g_print_len = 0;
	va_start(ap, str);
	if (!(guide = (t_guide *)ft_calloc(1, sizeof(t_guide))));
		return (0); // -1?
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, str[i++], 1);
			++g_print_len;
		}
		else
		{
			i = ft_fill_guide(str, i + 1, guide, ap);
			if (guide->format == '\0')
				continue;
			ft_print_result(guide, ap);
		}
	}
	free(guide);
	va_end(ap);
	return (g_print_len);
}

int		ft_fill_guide(const char *str, int i, t_guide guide, va_list ap)
{
	i = ft_fill_flag(str, i, guide);
	i = ft_fill_width(str, i, guide, ap);
	i = ft_fill_precision(str, i, guide, ap);
	i = ft_fill_format(str, i, guide);
	return (i);
}
